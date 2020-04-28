class Lemin {
  constructor() {
    this.stepNumber = -1;
    this.antsRooms = {};
  }

  render(data, container) {
    this.data = data;
    const elements = this.convertDataToElements(data);
    const style = this.getStyle();

    this.cy = cytoscape({
      container: container,
      style: style,
      elements: elements,
      layout: {
        name: 'preset'
      }
    });
  }

  reset() {
    this.stepNumber = -1;
    this.antsRooms = {};

    this.cy.startBatch();

    const roomsNames = Object.keys(this.data.rooms);
    roomsNames.forEach((roomName) => {
      this.clearRoom(roomName);
    });

    const startElement = this.cy.elements(`#${this.data.start}`);
    startElement.data({ ants: this.data.ants });
    this.hightlightRoom(this.data.start, "L1");

    this.data.links.forEach((link) => {
      this.unhightlightEdge(link[0], link[1]);
    })

    this.cy.endBatch();
  }

  goToStep(stepNumber) {
    this.cy.startBatch();
    this.reset();

    for (let i = 0; i <= stepNumber; i++) {
      const step = this.data.steps[i];
      const antsNames = Object.keys(step);

      antsNames.forEach((antName) => {
        const previousAntRoom = this.antsRooms[antName] || this.data.start;
        this.antsRooms[antName] = step[antName];

        this.removeAntFromRoom(previousAntRoom);
        this.addAntToRoom(step[antName], antName);
      });
    }

    this.cy.endBatch();

    this.stepNumber = stepNumber;
  }

  async playFromStep(stepNumber, checkIsStopped, onStepChanged, onFinished) {
    this.goToStep(stepNumber);

    if (checkIsStopped()) {
      return;
    }

    const startStep = Math.max(stepNumber, 0);

    for (let i = startStep; i < this.data.steps.length; i++) {
      const step = this.data.steps[i];
      const antsNames = Object.keys(step);

      antsNames.forEach((antName) => {
        const previousAntRoom = this.antsRooms[antName] || this.data.start;
        this.hightlightEdge(previousAntRoom, step[antName], antName);
      });

      await this.wait(checkIsStopped);

      antsNames.forEach((antName) => {
        const previousAntRoom = this.antsRooms[antName] || this.data.start;
        // this.unhightlightEdge(previousAntRoom, step[antName]);
        this.antsRooms[antName] = step[antName];

        this.removeAntFromRoom(previousAntRoom);
        this.addAntToRoom(step[antName], antName);
      });

      this.stepNumber = i;
      onStepChanged(i);

      await this.wait(checkIsStopped);
      if (checkIsStopped()) {
        return;
      }
    }

    onFinished();
  }

  convertDataToElements(data) {
    let minX = Number.MAX_SAFE_INTEGER;
    let minY = Number.MAX_SAFE_INTEGER;
    let maxX = Number.MIN_SAFE_INTEGER;
    let maxY = Number.MIN_SAFE_INTEGER;

    const roomsNames = Object.keys(data.rooms);
    roomsNames.forEach((roomName) => {
      const x = data.rooms[roomName].x;
      const y = data.rooms[roomName].y;
      minX = Math.min(minX, x);
      minY = Math.min(minY, y);
      maxX = Math.max(maxX, x);
      maxY = Math.max(maxY, x);
    });

    const scaleX = 1000 / (maxX - minX);
    const scaleY = 1000 / (maxY - minY);

    const nodes = roomsNames.map((roomName) => ({ data: { id: roomName, ants: data.start === roomName ? data.ants : 0 }, position: { x: data.rooms[roomName].x * scaleX, y: data.rooms[roomName].y * scaleY } }));
    const edges = data.links.map((link) => ({ data: { id: `${link[0]}-${link[1]}`, weight: 1, source: link[0], target: link[1] } }));

    const elements = {
      nodes: nodes,
      edges: edges
    };

    return elements;
  }

  getStyle() {
    const style = cytoscape.stylesheet()
      .selector('node')
      .style({
        'content': (element) => {
          const data = element.data();
          const content = data.ants > 1 ? `${data.id} (${data.ants})`: data.id;
          return content;
        }
      })
      .selector('edge')
      .style({
        'curve-style': 'bezier',
        'target-arrow-shape': 'triangle',
        'width': 8,
        'line-color': '#ddd',
        'target-arrow-color': '#ddd'
      })
      .selector('.highlighted-edge')
      .style({
        'transition-property': 'background-color, line-color, target-arrow-color',
        'transition-duration': '0.25s'
      })
      .selector('.highlighted-element')
      .style({
          "background-fit": "cover",
          "background-opacity": 1,
          "transition-property": "background-color, background-opacity",
          "transition-duration": "0.25s"
        })
        .selector(".highlighted-color-1")
        .style({
          "background-color": "#61bffc",
          'color': "#61bffc",
          "line-color": "#61bffc",
          "target-arrow-color": "#61bffc"
        })
        .selector(".highlighted-color-2")
        .style({
          "background-color": "#14D100",
          'color': "#14D100",
          "line-color": "#14D100",
          "target-arrow-color": "#14D100"
        })
        .selector(".highlighted-color-3")
        .style({
          "background-color": "#B70094",
          'color': "#B70094",
          "line-color": "#B70094",
          "target-arrow-color": "#B70094"
        })
        .selector(".highlighted-element-engaged")
        .style({
        'background-image': './images/ant.svg',
        'background-fit': 'cover',
        'background-opacity': 1,
        'transition-property': 'background-color, background-opacity',
        'transition-duration': '0.25s'
      });

    return style;
  }

  addAntToRoom(roomName, antName) {
    const roomElement = this.cy.elements(`#${roomName}`);
    const roomData = roomElement.data();
    roomElement.data({ ants: roomData.ants + 1 });
    this.hightlightRoom(roomName, antName);
    this.visitRoom(roomName);
  }

  removeAntFromRoom(roomName) {
    const roomElement = this.cy.elements(`#${roomName}`);
    const roomData = roomElement.data();
    const roomAnts = Math.max(roomData.ants - 1, 0);
    roomElement.data({ ants: roomAnts });
    if (roomAnts === 0) {
      this.leaveRoom(roomName);
    }
  }

  clearRoom(roomName) {
    const roomElement = this.cy.elements(`#${roomName}`);
    roomElement.data({ ants: 0 });
    this.unhightlightRoom(roomName);
    this.leaveRoom(roomName);
  }

  removeClassIfExist(elementName, edge) {
    const element =
      edge === true
        ? this.cy.edges(elementName)
        : this.cy.elements(elementName);
    if (element.length != 0) {
      const classToRemove = element.classes().find(className => {
        return className.match(/^highlighted-color-\d/g);
      });
      if (classToRemove) {
        this.cy.elements(elementName).removeClass(classToRemove);
      }
    }
  }

  hightlightRoom(roomName, antName) {
    this.removeClassIfExist(`#${roomName}`, false);
    const color =
      antName.slice(1) > 3 ? antName.slice(1) % 3 : antName.slice(1);
    this.cy
      .elements(`#${roomName}`)
      .addClass("highlighted-element")
      .addClass("highlighted-color-" + `${color}`);
  }

  visitRoom(roomName) {
    this.cy.elements(`#${roomName}`).addClass("highlighted-element-engaged");
  }

  unhightlightRoom(roomName) {
    this.removeClassIfExist(`#${roomName}`, false);
    this.cy.elements(`#${roomName}`).removeClass('highlighted-element');
  }

  leaveRoom(roomName) {
    this.cy.elements(`#${roomName}`).removeClass("highlighted-element-engaged");
  }

  hightlightEdge(from, to, antName) {
    const color =
      antName.slice(1) > 3 ? antName.slice(1) % 3 : antName.slice(1);
    this.removeClassIfExist(`#${from}-${to}`, true);
    this.removeClassIfExist(`#${to}-${from}`, true);
    this.cy
      .edges(`#${from}-${to}`)
      .addClass("highlighted-edge")
      .addClass("highlighted-color-" + `${color}`);
    this.cy
      .edges(`#${to}-${from}`)
      .addClass("highlighted-edge")
      .addClass("highlighted-color-" + `${color}`);
  }

  unhightlightEdge(from, to) {
    this.removeClassIfExist(`#${from}-${to}`, true);
    this.removeClassIfExist(`#${to}-${from}`, true);
    this.cy.edges(`#${from}-${to}`).removeClass("highlighted-edge");
    this.cy.edges(`#${to}-${from}`).removeClass("highlighted-edge");
  }

  async wait(checkIsStopped, delay = 500) {
    if (checkIsStopped()) {
      return Promise.resolve();
    }

    await new Promise((resolve) => {
      const timeout = setTimeout(() => {
        clearInterval(interval);
        resolve();
      }, delay);

      const interval = setInterval(() => {
        if (checkIsStopped()) {
          clearTimeout(timeout);
          clearInterval(interval);
          resolve();
        }
      }, 10);
    });
  }
}