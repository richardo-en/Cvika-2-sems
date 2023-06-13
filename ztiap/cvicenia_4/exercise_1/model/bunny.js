import { EnemyWithPositions } from "./enemy.js";
export class Bunny extends EnemyWithPositions {
    constructor() {
        super()
        this.name = "Wrathfull Bunny";
    }

    attack(target, demage) {
        let multiplication_number = Math.random();
        while (multiplication_number < 0.1) {
            multiplication_number = Math.random();
        }
        demage *= multiplication_number;
        target.defense(Math.floor(demage), target.name);
    }

    get strength() {
        return this.enemy_strength;
    }

    set strength(new_strength) {
        this.enemy_strength = new_strength;
    }

    get health() {
        return this.enemy_health;
    }

    set health(new_health) {
        this.enemy_health = new_health;
    }
}