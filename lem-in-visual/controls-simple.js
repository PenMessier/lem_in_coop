class ControlsSimple {
  constructor(lemin) {
    this.lemin = lemin;
  }

  render($container) {
    $container.removeClass('d-none');
    this.$play = $container.find('[data-play]');

    this.$play.on('click', () => this.onPlay());
  }

  async onPlay() {
    this.$play.attr('disabled', 'disabled');

    await this.lemin.play();

    this.$play.removeAttr('disabled');
  }
}