var game = new Phaser.Game(800, 600, Phaser.AUTO, "", {
  preload: preload,
  create: create,
  update: update
});

let platforms, ground, player, cursors, stars, items;
let score = 0,
  scoreText;

function preload() {
  game.load.image("sky", "assets/sky.png");
  game.load.image("ground", "assets/platform.png");
  game.load.image("star", "assets/star.png");
  game.load.spritesheet("dude", "assets/dude.png", 32, 48);
}

function createPlatform() {
  //  The platforms group contains the ground and the 2 ledges we can jump on
  platforms = game.add.group();

  //  We will enable physics for any object that is created in this group
  platforms.enableBody = true;

  // Here we create the ground.
  ground = platforms.create(0, game.world.height - 64, "ground");

  //  Scale it to fit the width of the game (the original sprite is 400x32 in size)
  ground.scale.setTo(2, 2);

  //  This stops it from falling away when you jump on it
  ground.body.immovable = true;

}

function createBackground() {
  //  A simple background for our game
  game.add.sprite(0, 0, "sky");
}

function createLedges() {
  //  Now let"s create two ledges
  var ledge = platforms.create(400, 400, "ground");

  ledge.body.immovable = true;

  ledge = platforms.create(-150, 250, "ground");

  ledge.body.immovable = true;
}

function createPlayer() {
  // The player and its settings
  player = game.add.sprite(32, game.world.height - 150, "dude");

  //  We need to enable physics on the player
  game.physics.arcade.enable(player);

  //  Player physics properties. Give the little guy a slight bounce.
  player.body.bounce.y = 0.2;
  player.body.gravity.y = 300;
  player.body.collideWorldBounds = true;

  //  Our two animations, walking left and right.
  player.animations.add("left", [0, 1, 2, 3], 10, true);
  player.animations.add("right", [5, 6, 7, 8], 10, true);

  player.inventory = [];
}

function createStars() {
  stars = game.add.group();

  stars.enableBody = true;

  //  Here we"ll create 12 of them evenly spaced apart
  for (var i = 0; i < 12; i++) {
    //  Create a star inside of the "stars" group
    var star = stars.create(i * 70, 0, "star");

    //  Let gravity do its thing
    star.body.gravity.y = 6;

    //  This just gives each star a slightly random bounce value
    star.body.bounce.y = 0.7 + Math.random() * 0.2;
  }
}

function createItems() {
  items = game.add.group();

  items.enableBody = true;

  //  Here we"ll create 12 of them evenly spaced apart
  for (var i = 0; i < 12; i++) {
    //  Create a star inside of the "stars" group
    var item = items.create(i * 70, 0, "star");
    item.name = "Health potion";
    //  Let gravity do its thing
    item.body.gravity.y = 8;
  }
}

function createScoreText() {
  // Set up score text
  scoreText = game.add.text(16, 16, 'score: 0', {
    fontSize: '32px',
    fill: '#000'
  });
}

function create() {
  // nable the Arcade Physics system
  game.physics.startSystem(Phaser.Physics.NINJA);

  createBackground();
  createPlatform();

  cursors = game.input.keyboard.createCursorKeys();

  createLedges();
  createPlayer();
  createStars();
  createItems();
  createScoreText();
}

function collectStar(player, star) {
  // Removes the star from the screen
  star.kill();

  //  Add and update the score
  score += 10;
  scoreText.text = 'Score: ' + score;
}

function collectItem(player, item) {
  // Remove the item from the screen ( alive, exists and visible all set to false)
  item.kill();

  player.inventory.push(item);
}

function update() {
  //  Collide the player and the stars with the platforms
  var hitPlatform = game.physics.arcade.collide(player, platforms);

  // Collide stars with platforms
  game.physics.arcade.collide(stars, platforms);

  game.physics.arcade.collide(items, platforms);

  game.physics.arcade.overlap(player, stars, collectStar, null, this);

  game.physics.arcade.overlap(player, items, collectItem, null, this);

  //  Reset the players velocity (movement)
  player.body.velocity.x = 0;

  if (cursors.left.isDown) {
    //  Move to the left
    player.body.velocity.x = -150;

    player.animations.play("left");
  } else if (cursors.right.isDown) {
    //  Move to the right
    player.body.velocity.x = 150;

    player.animations.play("right");
  } else {
    //  Stand still
    player.animations.stop();

    player.frame = 4;
  }

  //  Allow the player to jump if they are touching the ground.
  if (cursors.up.isDown && player.body.touching.down && hitPlatform) {
    player.body.velocity.y = -300;
  }

  // player.inventory.forEach(item => console.log(item.name));
}