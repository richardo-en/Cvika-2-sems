function create_random_number(){
    return Math.floor(Math.random() * (200 - 50) + 50)
}

export class Player {
    
    constructor() {
        this.player_strength = create_random_number();
        this.player_health = create_random_number();
        this.player_armour = create_random_number();
    }

    defense(attack_strengh , obejct_name) {
        let calculate_attack = this.player_armour -= attack_strengh;
        if (calculate_attack > 0) {
            return console.log("\nAttack was blocked!!");
        }else{
            this.player_health += calculate_attack;
            return console.log("\nAttack wasn't fully blocked. " + obejct_name + " health is " + this.player_health + ".");
        }
    }

    attack(enemy_target , demage) {
        enemy_target.defense(demage , enemy_target.name);
    }

    get strength(){
        return this.player_strength;
    }

    set strength(new_dmg){
        this.player_strength = new_dmg;
    }

    get health(){
        return this.player_health;
    }

    set health(new_health){
        this.player_health = new_health;
    }
}

