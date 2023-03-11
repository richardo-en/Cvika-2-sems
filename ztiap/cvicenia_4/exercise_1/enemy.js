function create_random_number() {
  return Math.floor(Math.random() * (200 - 50) + 50)
}

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

