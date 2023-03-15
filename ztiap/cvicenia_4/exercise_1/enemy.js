import { get_attack_range } from "./player.js";
import { get_jump } from "./player.js";
import { create_random_number } from "./player.js";

export class Enemy {

  constructor() {
    this.enemy_strength = create_random_number();
    this.enemy_health = create_random_number();
    this.enemy_armour = create_random_number();
  }

  defense(attack_strengh, object_name) {
    let calculate_attack = this.enemy_armour -= attack_strengh;
    if (calculate_attack > 0) {
      return console.log("\nAttack was blocked!!");
    } else {
      this.enemy_health += calculate_attack;
      return console.log("\nAttack wasn't fully blocked. " + object_name + " health is " + this.enemy_health + ".");
    }
  }

}

export class EnemyWithPositions extends Enemy {
  constructor() {
    super();
    this.position = {
      "position_x": 100 - get_attack_range(),
      "position_y": 100 - get_attack_range()
    }
    this.attack_range = get_attack_range();
  }

  jump() {
    if (this.position_x < 100 && (this.position_x + get_jump() <= 100 && this.position_x + get_jump() >= 0) && (this.position_y + get_jump() >= 0 && this.position_y + get_jump() <= 100)) {
      this.position_x += get_jump();
      this.position_y += get_jump();
    } else {
      this.jump()
    }
  }
  get position_x() {
    return this.position.position_x;
  }

  set position_x(new_x) {
    this.position.position_x = new_x;
  }

  get position_y() {
    return this.position.position_y;
  }

  set position_y(new_y) {
    this.position.position_y = new_y;
  }

  get attack_range() {
    return this.attack_range;
  }

  set attack_range(new_range) {
    super.attack_range = new_range;
  }
}