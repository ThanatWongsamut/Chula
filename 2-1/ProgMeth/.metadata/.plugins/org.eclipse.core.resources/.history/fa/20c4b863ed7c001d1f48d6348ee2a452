package logic;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.BufferedInputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.UnsupportedAudioFileException;

import application.EndState;
import application.Main;
import application.WonState;
import gui.enemy.EnemyPane;
import gui.enemy.KingViperPane;
import gui.floor.FloorPane;
import gui.player.PlayerPane;
import gui.score.ScorePane;
import gui.timer.GameTimerPane;
import gui.weapon.bullet.Bullet;
import gui.weapon.inventory.WeaponInventory;
import gui.weapon.weapon.ElderflameGun;
import gui.weapon.weapon.FlameThrowerGun;
import gui.weapon.weapon.LaserGun;
import gui.weapon.weapon.MachineGun;
import gui.weapon.weapon.PistolGun;
import gui.weapon.weapon.RifleGun;
import gui.weapon.weapon.ShotGun;
import gui.weapon.weapon.Weapon;
import javafx.application.Platform;
import javafx.scene.Scene;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class GameLogic {

	private static FloorPane floorPane;
	private static PlayerPane playerPane;
	private static ArrayList<EnemyPane> enemyPanes;
	private static KingViperPane kingViper;
	private static Weapon elderflameGun;
	private static Weapon flameThrowerGun;
	private static Weapon laserGun;
	private static Weapon machineGun;
	private static Weapon pistolGun;
	private static Weapon rifleGun;
	private static Weapon shotGun;

	private static Weapon equippedWeapon;
	private static WeaponInventory weaponInventory;

	private static ArrayList<Bullet> bulletList;
	private static int score;

	private static ScorePane scorePane;
	private static GameTimer gameTimer;
	private static GameTimerPane gameTimerPane;
	private static boolean startGame;

	private static Scene playScene;
	private static Scene titleScene;
	private static Scene endScene;
	private static Scene wonScene;
	private static int viperKillStack, multiply;

	private static Clip player;

	public static void gameStart(Stage primaryStage, Scene playScene, StackPane root) {

		setStartGame(true);
		
		setScore(0);
		setViperKillStack(0);
		setMultiply(1);

		initializeFloor(root);

		initializePlayer(root);

		initializeWeapon(root);

		initializeWeaponInventory(root);

		initializeBullet();

		initializeEnemy(root);

		addControlEventHandler(root);

		addShootEventHandler(root);

		startUpdateTimeThread(primaryStage, root);

		startCheckPlayerGetBiteThread(primaryStage, root);

		startViperSpawnThread(primaryStage, root);

		startViperRespawnThread(primaryStage, root);

		initializeScorePane(root);
	}

	private static void initializeFloor(StackPane root) {
		// Initialize and add floorPane to root
		floorPane = new FloorPane();
		root.getChildren().add(floorPane);
	}

	private static void initializePlayer(StackPane root) {
		// Initialize and add playerPane to root
		playerPane = new PlayerPane(0, 0);
		root.getChildren().add(playerPane);
		playerPane.run();
		playerPane.animate();
		playerPane.setImmune(false);
	}

	private static void initializeEnemy(StackPane root) {
		// Initialize and add 3 enemyPane to root
		int[] spawnPoint1 = getSpawnPoint();
		int[] spawnPoint2 = getSpawnPoint();
		int[] spawnPoint3 = getSpawnPoint();
		enemyPanes = new ArrayList<EnemyPane>(Arrays.asList(new EnemyPane(spawnPoint1[0], spawnPoint1[1]),
				new EnemyPane(spawnPoint2[0], spawnPoint2[1]), new EnemyPane(spawnPoint3[0], spawnPoint3[1])));

		root.getChildren().add(enemyPanes.get(0));
		enemyPanes.get(0).run();
		enemyPanes.get(0).animate();
		root.getChildren().add(enemyPanes.get(1));
		enemyPanes.get(1).run();
		enemyPanes.get(1).animate();
		root.getChildren().add(enemyPanes.get(2));
		enemyPanes.get(2).run();
		enemyPanes.get(2).animate();
	}

	private static void initializeViperKing(StackPane root) {
		// Initialize and add kingViperPane to root
		kingViper = new KingViperPane(0, -300);
		
		enemyPanes.add(kingViper);
		Platform.runLater(new Runnable() {
			public void run() {
				root.getChildren().add(kingViper);
			}
		});
		
		kingViper.run();
		kingViper.animate();
	}

	private static void initializeWeapon(StackPane root) {
		// Initialize all weapon
		elderflameGun = new ElderflameGun(0, 0);
		flameThrowerGun = new FlameThrowerGun(0, 0);
		laserGun = new LaserGun(0, 0);
		machineGun = new MachineGun(0, 0);
		pistolGun = new PistolGun(0, 0);
		rifleGun = new RifleGun(0, 0);
		shotGun = new ShotGun(0, 0);

		// Run all thread in all weapon
		elderflameGun.run();
		flameThrowerGun.run();
		laserGun.run();
		machineGun.run();
		pistolGun.run();
		rifleGun.run();
		shotGun.run();

		// Set default weapon to pistol
		setWeapon(pistolGun);

		// Add weapon to root
		root.getChildren().add(equippedWeapon);
	}

	private static void initializeWeaponInventory(StackPane root) {
		weaponInventory = new WeaponInventory();
		weaponInventory.update();
		root.getChildren().add(weaponInventory);
	}

	private static void initializeBullet() {
		// Initialize bullet list
		bulletList = new ArrayList<Bullet>();
	}

	private static void initializeScorePane(StackPane root) {
		// Initialize and add scorePane to root
		scorePane = new ScorePane();
		root.getChildren().add(scorePane);
		scorePane.run();
	}

	private static void startUpdateTimeThread(Stage primaryStage, StackPane root) {
		// Initialize gameTimer and gameTimerPane
		gameTimer = new GameTimer();
		gameTimerPane = new GameTimerPane(gameTimer.toString());

		// Start timer thread
		Thread updateTimeThread = new Thread(() -> {
			while (isStartGame()) {
				Platform.runLater(new Runnable() {
					public void run() {
						gameTimerPane.updateGameTimer(gameTimer.toString());
					}
				});

				delay(20);

			}
		});

		updateTimeThread.start();

		// Add gameTimerPane to root
		root.getChildren().add(gameTimerPane);

		// Start timer
		GameTimer.timer();
	}

	private static void startCheckPlayerGetBiteThread(Stage primaryStage, StackPane root) {
		Thread checkPlayerGetBiteThread = new Thread(() -> {
			// Loop while game is start
			while (isStartGame()) {

				// Copy list (prevent concurrent modification)
				ArrayList<EnemyPane> enemyBiteCheck = new ArrayList<EnemyPane>(enemyPanes);

				// Check if player has bite
				for (EnemyPane enemy : enemyBiteCheck) {
					if (enemy != null && !enemy.isDead() && canEnemyBite(enemy) && !playerPane.isImmune()) {
						playerPane.setImmune(true);
						setViperKillStack(0);
						updateMultiply();
						playerGetBite(enemy);

						break;
					}

				}

				// Check player is dead
				if (playerPane.isDead()) {

					// Stop game after player is dead
					gameStop(root);

					// Play ending background music
					playBackgroundMusic("endbg.wav");

					// Change scene to ending and stop playing game
					Platform.runLater(() -> {
						setEndScene(new Scene(new EndState(root, primaryStage)));
						primaryStage.setScene(getEndScene());
					});
					break;
				}

				// Set player immune for 2 second after bite
				if (playerPane.isImmune()) {
					delay(2000);
					playerPane.setImmune(false);
				}

			}
		});

		checkPlayerGetBiteThread.start();
	}

	private static void startViperSpawnThread(Stage primaryStage, StackPane root) {
		Thread viperSpawnThread = new Thread(() -> {
			// Loop while gane is started and Time start less than 5 minutes
			while (isStartGame() && GameTimer.getMin() < 5) {
				delay(100);

				// Spawn new enemy every 20 seconds
				if (GameTimer.getSec() % 20 == 0 && !(GameTimer.getMin() == 0 && GameTimer.getSec() == 0)) {
					int[] spawnPoint = getSpawnPoint();
					EnemyPane newEnemy = new EnemyPane(spawnPoint[0], spawnPoint[1]);
					enemyPanes.add(0, newEnemy);
					Platform.runLater(new Runnable() {
						public void run() {
							root.getChildren().add(newEnemy);
						}
					});

					newEnemy.run();
					newEnemy.animate();

					delay(1000);
				}
			}
			// Add one last Boss after 5 Minutes
			if (GameTimer.getMin() >= 5) {			
				initializeViperKing(root);
			}

		});

		viperSpawnThread.start();
	}

	private static void startViperRespawnThread(Stage primaryStage, StackPane root) {
		Thread viperRespawnThread = new Thread(() -> {
			// Loop while game is started
			while (isStartGame()) {

				// Check if enemy need to re-spawn
				if (enemyPanes.toArray().length > 0) {
					for (Object enemy : enemyPanes.toArray()) {
						if (enemy != null && ((EnemyPane) enemy).needRespawn()) {
							// Increase player score and multiplier also check player can heal
							if (((EnemyPane) enemy).getScore() > 0) {
								setViperKillStack(getViperKillStack() + 1);
								updateMultiply();
								setScore(getScore() + ((EnemyPane) enemy).getScore() * getMultiply());
								((EnemyPane) enemy).setScore(0);
								Platform.runLater(() -> {
									getPlayerPane().checkHeal();
								});
							}

							// Remove old enemy
							enemyPanes.remove(enemy);
							Platform.runLater(() -> {
								root.getChildren().remove(enemy);
							});

							// Spawn new enemy
							if (kingViper == null || !kingViper.isDead()) {
								int[] spawnPoint = getSpawnPoint();
								EnemyPane newEnemy = new EnemyPane(spawnPoint[0], spawnPoint[1]);
								if (!newEnemy.isDead()) {
									newEnemy.run();
									newEnemy.animate();

									Platform.runLater(new Runnable() {
										public void run() {
											root.getChildren().add(newEnemy);
										}
									});
									enemyPanes.add(newEnemy);
								}
							}

							break;
						}
					}
				} else {
					Platform.runLater(() -> {
						setWonScene(new Scene(new WonState(root, primaryStage)));
						primaryStage.setScene(getWonScene());
						GameLogic.playBackgroundMusic("winbg.wav");
					});
					gameStop(root);
					break;
				}
				delay(20);
			}
		});

		viperRespawnThread.start();
	}

	private static void addControlEventHandler(StackPane root) {
		playScene.addEventHandler(KeyEvent.KEY_PRESSED, (key) -> {
			playerPane.keyPressHandler(key);
		});

		playScene.addEventHandler(KeyEvent.KEY_RELEASED, (key) -> {
			playerPane.keyReleasedHandler(key);
		});

		playScene.addEventHandler(KeyEvent.KEY_RELEASED, (key) -> {
			// Select weapon from input key and predetermined period
			if (key.getCode() == KeyCode.DIGIT1) {
				changeWeaponToPistolGun(root);
			}

			if (key.getCode() == KeyCode.DIGIT2 && GameTimer.getMin() >= 1) {
				changeWeaponToRifleGun(root);
			}

			if (key.getCode() == KeyCode.DIGIT3 && GameTimer.getMin() >= 1) {
				changeWeaponToShotGun(root);
			}

			if (key.getCode() == KeyCode.DIGIT4 && GameTimer.getMin() >= 3) {
				changeWeaponToMachineGun(root);
			}

			if (key.getCode() == KeyCode.DIGIT5 && GameTimer.getMin() >= 3) {
				changeWeaponToLaserGun(root);
			}

			if (key.getCode() == KeyCode.DIGIT6 && GameTimer.getMin() >= 3) {
				changeWeaponToFlameThrowerGun(root);
			}

			if (key.getCode() == KeyCode.BACK_SPACE) {
				changeWeaponToElderflameGun(root);
			}
		});
	}

	private static void addShootEventHandler(StackPane root) {
		playScene.setOnMousePressed(event -> {
			if (!getWeapon().getAlreadyShoot()) {
				getWeapon().startShoot();
				getWeapon().runShoot(root);
				getWeapon().setShootPosition(event);
			}
		});

		playScene.setOnMouseDragged(event -> {
			getWeapon().setShootPosition(event);
		});

		playScene.setOnMouseReleased(event -> {
			getWeapon().endShoot();
		});
	}

	public static void changeWeaponToElderflameGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(elderflameGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToFlameThrowerGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(flameThrowerGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToLaserGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(laserGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToMachineGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(machineGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToPistolGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(pistolGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToRifleGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(rifleGun);
		root.getChildren().add(equippedWeapon);
	}

	public static void changeWeaponToShotGun(StackPane root) {
		equippedWeapon.endShoot();
		root.getChildren().remove(equippedWeapon);
		setWeapon(shotGun);
		root.getChildren().add(equippedWeapon);
	}

	// Check 2 Object overlaps
	public static boolean overlaps(double point1, double length1, double point2, double length2) {
		double highestStartPoint = Math.max(point1, point2);
		double lowestEndPoint = Math.min(point1 + length1, point2 + length2);
	
		return highestStartPoint < lowestEndPoint;
	}

	// check collision between enemy and bullet
	public static boolean isCollision(EnemyPane enemy, Bullet bullet) {
		if (overlaps(enemy.getxTranslation() - enemy.getPrefWidth() / 2, enemy.getPrefWidth(),
				bullet.getxTranslation() - 16, 32)
				&& overlaps(enemy.getyTranslation() - enemy.getPrefHeight() / 2, enemy.getPrefHeight(),
						bullet.getyTranslation() - 16, 32)) {
			enemy.receiveDamage(bullet);
			return true;
		}
		return false;
	}

	// check enemy overlaps with player
	public static boolean canEnemyBite(EnemyPane enemy) {
		return overlaps(enemy.getxTranslation() - enemy.getPrefWidth() / 2, enemy.getPrefWidth(),
				playerPane.getxTranslation() - 16, 32)
				&& overlaps(enemy.getyTranslation() - enemy.getPrefHeight() / 2, enemy.getPrefHeight(),
						playerPane.getyTranslation() - 16, 32);
	}

	public static void playerGetBite(EnemyPane enemy) {
		// After player get bite receive damage
		if (canEnemyBite(enemy)) {
			playerPane.receiveDamage(enemy.getBite());
		}
	}

	public static int[] getSpawnPoint() {
		// Random enemy spawn point
		int randomSpawn, xSpawn, ySpawn;
		randomSpawn = new Random().nextInt(3);
	
		if (randomSpawn == 0) {
			xSpawn = (int) (-300 + 600 * Math.random());
			ySpawn = -300;
		} else if (randomSpawn == 1) {
			xSpawn = 300;
			ySpawn = (int) (-300 + 600 * Math.random());
		} else if (randomSpawn == 2) {
			xSpawn = -300;
			ySpawn = (int) (-300 + 600 * Math.random());
		} else {
			xSpawn = (int) (-300 + 600 * Math.random());
			ySpawn = 300;
		}
		int[] spawnPoint = { xSpawn, ySpawn };
		return spawnPoint;
	}

	public static void gameStop(StackPane root) {
		if (playerPane != null)
			playerPane.setMovingThreadStart(false);
		GameTimer.setTimerControl(false);
		setStartGame(false);
		if (enemyPanes != null) {
			for (int i = 0; i < enemyPanes.size(); i++) {
				enemyPanes.get(i).setMovingThreadStart(false);
			}
		}
		if (equippedWeapon != null)
			equippedWeapon.endShoot();
		if (bulletList != null) {
			for (int i = 0; i < bulletList.size(); i++) {
				bulletList.get(i).setMovingThreadStart(false);
			}
		}
		Platform.runLater(() -> {
			root.getChildren().clear();
		});
	
	}

	public static int getMultiply() {
		return multiply;
	}

	public static void setMultiply(int multiply) {
		GameLogic.multiply = Math.min(20, multiply);
	}

	public static void updateMultiply() {
		setMultiply(getViperKillStack() / 10 + 1);
	}

	public static void playBackgroundMusic(String path) {
		try {
			InputStream musicFileStream = Main.class.getResourceAsStream("/music/" + path);
			InputStream bufferedMusicFile = new BufferedInputStream(musicFileStream);
			AudioInputStream musicFile = AudioSystem.getAudioInputStream(bufferedMusicFile);
			getPlayer().stop();
			getPlayer().close();
			getPlayer().open(musicFile);
			getPlayer().loop(Clip.LOOP_CONTINUOUSLY);
			getPlayer().start();
		} catch (UnsupportedAudioFileException e) {
			System.out.println("BG music not found");
		} catch (LineUnavailableException e) {
			System.out.println("Error in music player");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void stopBackgroundMusic() {
		getPlayer().stop();
	}

	public static void delay(int ms) {
		try {
			Thread.sleep(ms);
			Thread.yield();
		} catch (InterruptedException e) {
			System.out.println("Sleep thread error");
		}
	}

	public static boolean setHighScore() {
	
		try {
			File saveFile = new File("save.txt");
	
			if (!saveFile.exists()) {
				// If save file is not exist -> write new one
				PrintWriter writer = new PrintWriter("save.txt", "UTF-8");
				writer.println(getScore());
				writer.close();
				return true;
			} else {
				// If it exist -> compare with latest score
				Scanner fileReader = new Scanner(saveFile);
	
				if (fileReader.hasNextLine()) {
	
					String oldScore = fileReader.nextLine();
					fileReader.close();
	
					if (oldScore == "" || Integer.valueOf(oldScore) < getScore()) {
						// Overwrite last highest score
						PrintWriter fileWriter = new PrintWriter(new FileOutputStream("save.txt", false));
						fileWriter.println(getScore());
						fileWriter.close();
						return true;
					}
				}
	
				fileReader.close();
			}
		} catch (IOException e) {
			System.out.println("Saving error");
		}
		return false;
	}

	public static String getHighScore() {
		try {
			File saveFile = new File("save.txt");
			Scanner fileReader = new Scanner(saveFile);
	
			if (fileReader.hasNextLine()) {
				String score = "Highest Score : " + fileReader.nextLine();
				fileReader.close();
				return score;
			}
	
			fileReader.close();
	
			return "Highest Score : None";
	
		} catch (FileNotFoundException e) {
			return "Highest Score : None";
		}
	}

	// Add custom font
	public static Font font(double size) {
		InputStream fontFileStream = Main.class.getResourceAsStream("/Font/VT323-Regular.ttf");
		return Font.loadFont(fontFileStream, size);
	}

	public static FloorPane getFloorPane() {
		return floorPane;
	}

	public static void setFloorPane(FloorPane floorPane) {
		GameLogic.floorPane = floorPane;
	}

	public static PlayerPane getPlayerPane() {
		return playerPane;
	}

	public static void setPlayerPane(PlayerPane playerPane) {
		GameLogic.playerPane = playerPane;
	}

	public static ArrayList<EnemyPane> getEnemyPane() {
		return enemyPanes;
	}

	public static void setEnemyPane(ArrayList<EnemyPane> enermyPane) {
		enemyPanes = enermyPane;
	}

	public static GameTimer getGameTimer() {
		return gameTimer;
	}

	public static void setGameTimer(GameTimer gameTimer) {
		GameLogic.gameTimer = gameTimer;
	}

	public static GameTimerPane getGameTimerPane() {
		return gameTimerPane;
	}

	public static void setGameTimerPane(GameTimerPane gameTimerPane) {
		GameLogic.gameTimerPane = gameTimerPane;
	}

	public static Weapon getWeapon() {
		return equippedWeapon;
	}
	
	public static void setWeapon(Weapon weapon) {
		equippedWeapon = weapon;
	}

	public static KingViperPane getKingViper() {
		return kingViper;
	}

	public static Scene getPlayScene() {
		return playScene;
	}

	public static void setPlayScene(Scene playScene) {
		GameLogic.playScene = playScene;
	}

	public static Scene getTitleScene() {
		return titleScene;
	}

	public static void setTitleScene(Scene titleScene) {
		GameLogic.titleScene = titleScene;
	}

	public static Scene getEndScene() {
		return endScene;
	}

	public static void setWonScene(Scene wonScene) {
		GameLogic.wonScene = wonScene;
	}

	public static Scene getWonScene() {
		return wonScene;
	}

	public static void setEndScene(Scene endScene) {
		GameLogic.endScene = endScene;
	}

	public static int getScore() {
		return score;
	}

	public static void setScore(int score) {
		GameLogic.score = score;
	}

	public static int getViperKillStack() {
		return viperKillStack;
	}

	public static void setViperKillStack(int viperKillStack) {
		GameLogic.viperKillStack = viperKillStack;
	}

	public static boolean isStartGame() {
		return startGame;
	}
	
	public static boolean getStartGame() {
		return startGame;
	}

	public static void setStartGame(boolean startGame) {
		GameLogic.startGame = startGame;
	}

	public static Clip getPlayer() {
		return player;
	}

	public static void setPlayer(Clip player) {
		GameLogic.player = player;
	}
}
