window.onload = function() {
    //  Note that this html file is set to pull down Phaser 2.5.0 from the JS Delivr CDN.
    //  Although it will work fine with this tutorial, it"s almost certainly not the most current version.
    //  Be sure to replace it with an updated version before you start experimenting with adding your own code.

    let paddle;
    let ball;
    let bricks;

    let ballOnPaddle = true;

    let lives = 3;
    let score = 0;

    let scoreText;
    let livesText;
    let introText;

    const game = new Phaser.Game(
      800, 600,
       Phaser.AUTO, "game", { preload: preload, create: create, update: update });

    function preload () {
        game.load.image("paddle", "paddle.png");
        game.load.image("brick", "brick.png");
        game.load.image("ball", "ball.png");
    }

    function create () {
        // Setup game and physics
        game.stage.backgroundColor = '#111';
        game.physics.startSystem(Phaser.Physics.ARCADE);
        game.physics.arcade.checkCollision.down = false;

        // Create paddle
        paddle = game.add.sprite(game.world.centerX, 600, "paddle");
        paddle.anchor.setTo(0.5, 0.5);
        game.physics.enable(paddle, Phaser.Physics.ARCADE);
        paddle.body.collideWorldBounds = true;
        paddle.body.bounce.set(1);
        paddle.body.immovable = true;

        // Create ball
        ball = game.add.sprite(game.world.centerX, game.world.centerY, "ball");
        game.physics.enable(ball, Phaser.Physics.ARCADE);
        ball.body.velocity.x=100;
        ball.body.velocity.y=100;
        ball.checkWorldBounds = true;
        // ball.body.collideWorldBounds = true;
        ball.body.collideWorldBounds = true;
        ball.body.bounce.set(1);
        ball.anchor.setTo(0.5, 0.5);

        ball.events.onOutOfBounds.add(ballLost, this);

        scoreText = game.add.text(32, 550, 'score: 0', { font: "20px Arial", fill: "#ffffff", align: "left" });
        livesText = game.add.text(680, 550, 'lives: 3', { font: "20px Arial", fill: "#ffffff", align: "left" });
        introText = game.add.text(game.world.centerX, 400, '- click to start -', { font: "40px Arial", fill: "#ffffff", align: "center" });
        introText.anchor.setTo(0.5, 0.5);

        game.input.onDown.add(releaseBall, this);


        // Create bricks
        bricks = game.add.group();
        bricks.enableBody = true;
        bricks.physicsBodyType = Phaser.Physics.ARCADE;
        const ROWS = 4, COLS = 5, OFFSET = 20, BRICK_W = 120, BRICK_H = 35;

        let brick;
        for (let i = 1; i <= ROWS; i += 1) {
          for (let j = 0; j <= COLS; j += 1) {
            const x = j * (BRICK_W + OFFSET);
            const y = i * (BRICK_H + OFFSET);
            brick = bricks.create(x, y, "brick");
            brick.body.bounce.set(1);
            brick.body.immovable = true;
          }
        }
    }

    function update () {
      paddle.x = game.input.x;

      if (paddle.x < 24) {
          paddle.x = 24;
      } if (paddle.x > game.width - 24) {
          paddle.x = game.width - 24;
      }

      if (ballOnPaddle) {
          ball.body.x = paddle.x;
      } else {
          game.physics.arcade.collide(ball, paddle, ballHitPaddle, null, this);
          game.physics.arcade.collide(ball, bricks, ballHitBrick, null, this);
      }
    }

    function releaseBall () {
      if (ballOnPaddle) {
          ballOnPaddle = false;
          ball.body.velocity.y = -300;
          ball.body.velocity.x = -75;
          introText.visible = false;
      }
    }

  function ballLost () {
      lives--;
      livesText.text = 'lives: ' + lives;
      if (lives === 0) {
          gameOver();
      } else {
          ballOnPaddle = true;
          ball.reset(paddle.body.x + 16, paddle.y - 16);
      }

  }

  function gameOver () {
      ball.body.velocity.setTo(0, 0);
      introText.text = 'Game Over!';
      introText.visible = true;
  }

  function ballHitBrick (_ball, _brick) {
      _brick.kill();

      score += 10;

      scoreText.text = 'score: ' + score;

      //  Are they any bricks left?
      if (bricks.countLiving() == 0) {
          //  New level starts
          score += 1000;
          scoreText.text = 'score: ' + score;
          introText.text = '- Next Level -';

          //  Let's move the ball back to the paddle
          ballOnPaddle = true;
          ball.body.velocity.set(0);
          ball.x = paddle.x + 16;
          ball.y = paddle.y - 16;
          ball.animations.stop();

          //  And bring the bricks back from the dead :)
          bricks.callAll('revive');
      }
  }

  function ballHitPaddle (_ball, _paddle) {
      var diff = 0;

      if (_ball.x < _paddle.x) {
          //  Ball is on the left-hand side of the paddle
          diff = _paddle.x - _ball.x;
          _ball.body.velocity.x = (-10 * diff);
      } else if (_ball.x > _paddle.x) {
          //  Ball is on the right-hand side of the paddle
          diff = _ball.x -_paddle.x;
          _ball.body.velocity.x = (10 * diff);
      } else {
          //  Ball is perfectly in the middle
          //  Add a little random X to stop it bouncing straight up!
          _ball.body.velocity.x = 2 + Math.random() * 8;
      }
  }
};
