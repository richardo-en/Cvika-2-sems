export function create_random_number() {
    return Math.floor(Math.random() * (200 - 50) + 50)
}

export function get_jump() {
    return Math.floor(Math.random() * 11) - 5;
}

export function get_attack_range() {
    return Math.floor(Math.random() * 11);
}

export class Player {

    constructor() {
        this.player_strength = create_random_number();
        this.player_health = create_random_number();
        this.player_armour = create_random_number();
    }

    defense(attack_strengh, obejct_name) {
        let calculate_attack = this.player_armour -= attack_strengh;
        if (calculate_attack > 0) {
            return console.log("\nAttack was blocked!!");
        } else {
            this.player_health += calculate_attack;
            return console.log("\nAttack wasn't fully blocked. " + obejct_name + " health is " + this.player_health + ".");
        }
    }

    attack(enemy_target, demage) {
        enemy_target.defense(demage, enemy_target.name);
    }

    get strength() {
        return this.player_strength;
    }

    set strength(new_dmg) {
        this.player_strength = new_dmg;
    }

    get health() {
        return this.player_health;
    }

    set health(new_health) {
        this.player_health = new_health;
    }

}

export class PlayerWithPositions extends Player {
    constructor() {
        super();
        this.position = {
            "position_x": get_attack_range(),
            "position_y": get_attack_range()
        };
        this.attack_range = get_attack_range();
    }

    jump() {
        if (this.position_x < 100 && (this.position_x + get_jump() <= 100) && (this.position_x + get_jump() >= 0)) {
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
