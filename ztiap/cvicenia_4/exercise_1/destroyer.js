import { Enemy } from './enemy.js';
export class Destroyer extends Enemy {
  constructor() {
    super()
    this.name = "Pinky Ass Destroyer";
  }

  attack(target, demage) {
    let multiplication_number = Math.random() * 2 + 1;
    while (multiplication_number < 1) {
      multiplication_number = Math.random() * 2 + 1;
    }
    demage *= multiplication_number;
    target.defense(Math.floor(demage), target.name);
  }

  get strength() {
    return this.enemy_strength;
  }

  set strength(some_shit) {
    this.enemy_strength += some_shit;
  }

  get health() {
    return this.enemy_health;
  }

  set health(new_health) {
    this.enemy_health = new_health;
  }
}