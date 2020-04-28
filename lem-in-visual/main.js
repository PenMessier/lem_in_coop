(function($) {
  const isSimple = false;

  $(async function() {
    const response = await fetch("./data.json");
    const data = await response.json();
    const container = document.getElementById("main");

    if (isSimple) {
      const lemin = new LeminSimple();
      lemin.render(data, container);

      const $controlsContainer = $("#controls-simple");

      const control = new ControlsSimple(lemin);
      control.render($controlsContainer);
    } else {
      const lemin = new Lemin();
      lemin.render(data, container);

      const $controlsContainer = $("#controls");

      const control = new Controls(lemin);
      control.render($controlsContainer);
    }
  });
})(jQuery);
