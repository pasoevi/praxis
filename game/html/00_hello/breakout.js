window.onload = function() {
    //  Note that this html file is set to pull down Phaser 2.5.0 from the JS Delivr CDN.
    //  Although it will work fine with this tutorial, it's almost certainly not the most current version.
    //  Be sure to replace it with an updated version before you start experimenting with adding your own code.
    const game = new Phaser.Game(
      800, 600,
       Phaser.AUTO, "game", { preload: preload, create: create });

    const bricks = [];
    const ROWS = 5, COLS = 20, OFFSET = 10, BRICK_W = 50, BRICK_H = 20;

    for (let i = 0; i < ROWS; i += 1) {
      for (let j = 0; j < COLS; j += 1) {
        bricks.push({
          x: i * (BRICK_H + OFFSET),
          y: j * (BRICK_W + OFFSET)
        });
      }
    }

    function preload () {
        game.load.image('logo', 'paddle.png');
    }

    function create () {
        const logo = game.add.sprite(game.world.centerX, 600, 'logo');
        logo.anchor.setTo(0.5, 0.5);
    }
  };
