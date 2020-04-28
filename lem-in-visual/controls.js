class Controls {
  constructor(lemin) {
    this.lemin = lemin;

    this.step = -1;
    this.isPlaying = false;
  }

  render($container) {
    $container.removeClass("d-none");

    this.$playPause = $container.find("[data-play-pause]");
    this.$reset = $container.find("[data-reset]");
    this.$step = $container.find("[data-step]");

    this.$step.attr("min", -1);
    this.$step.attr("max", this.lemin.data.steps.length - 1);
    this.$step.val(this.step);

    this.$playPause.on("click", () => this.onPlayPause());
    this.$reset.on("click", () => this.onReset());
    this.$step.on("change", () => this.onStepChanged(+this.$step.val()));
  }

  async onPlayPause() {
    if (this.isPlaying) {
      this.onPause();
    } else {
      this.onPlay();
    }
  }

  onReset() {
    if (this.isPlaying) {
      this.onPause();
    }

    setTimeout(() => {
      this.onStepChanged(-1);
      this.$step.val(-1);
    }, 20);
  }

  onPlay() {
    this.$playPause
      .find("[data-icon]")
      .removeClass("fa-play")
      .addClass("fa-pause");
    this.isPlaying = true;

    let fromStep;
    if (this.step === this.lemin.data.steps.length - 1) {
      fromStep = -1;
    } else {
      fromStep = this.step;
    }

    const checkIsStopped = () => !this.isPlaying;
    this.lemin.playFromStep(
      fromStep,
      checkIsStopped,
      step => this.onStepPlayed(step),
      () => this.onPlayFinished()
    );
  }

  onPause() {
    this.$playPause
      .find("[data-icon]")
      .addClass("fa-play")
      .removeClass("fa-pause");
    this.isPlaying = false;
  }

  onStepChanged(step) {
    this.step = step;
    if (this.isPlaying) {
      this.onPause();
    }
    this.lemin.goToStep(step);
  }

  onStepPlayed(step) {
    this.step = step;
    this.$step.val(step);
  }

  onPlayFinished() {
    this.onPause();
  }
}
