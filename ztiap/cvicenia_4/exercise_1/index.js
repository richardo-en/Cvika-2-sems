import { Bunny } from "./model/bunny.js";
import { Destroyer } from "./model/destroyer.js";
import { PlayerWithPositions } from "./model/player.js";

var fight_count = 0;
var enemy_turn_count = 0;
var enemy_to_target = 0;
const new_player = new PlayerWithPositions();
const wrathfull_bunny = new Bunny('red');
const pinky_ass_destroyer = new Destroyer('orange');

new_player.draw_player();
export function move_player_around(x, y, direction){
    new_player.move_player(x, y, direction)
}
pinky_ass_destroyer.draw_enemy();


// while (fight_count != 100) {
    //     test();
    //     fight_count++;
    // if(fight_count % 2 == 0) {
        //     let enemy_target = get_enemy_target();
        //     if (is_in_distance(enemy_to_target.position_x, enemy_to_target.position_y, new_player.attack_range)) {
            //         new_player.attack(enemy_target, new_player.strength);
            //         enemy_to_target++;
            //     }else{
                //         new_player.jump();
                //     }
                // }else{
                    //     let specified_enemy_to_attack = enemy_turn();
                    //     if (is_in_distance(specified_enemy_to_attack.position_x, specified_enemy_to_attack.position_y, specified_enemy_to_attack.attack_range)) {
                        //         specified_enemy_to_attack.attack(new_player, specified_enemy_to_attack.strength);
                        //         enemy_turn_count++;
                        //     }else{
                            //         specified_enemy_to_attack.jump();
                            //     }
                            // }
                            
                            // if (new_player.health < 0) {
                                //     console.log("\nPlayer has lost battle");
                                //     break;
                                // } else if (pinky_ass_destroyer.health < 0 && wrathfull_bunny.health < 0) {
                                    //     console.log("\nPlayer has won battle");
                                    //     break;
                                    // }
                                    // fight_count++;
                                    // }
                                    
function get_enemy_target() {
    if (enemy_to_target % 2 == 0) {
        return wrathfull_bunny
    } else {
        return pinky_ass_destroyer
    }
}

function enemy_turn() {
    if (enemy_turn_count % 2 == 0) {
        return wrathfull_bunny
    } else {
        return pinky_ass_destroyer
    }
}

function is_in_distance(enemy_x, enemy_y , difference){
    if ((new_player.position_x - enemy_x >= -difference || new_player.position_x - enemy_x <= difference) && (new_player.position_y - enemy_y >= -difference || new_player.position_y - enemy_y <= difference) )  {
        return true;
    }else{
        return false;
    }
}
// module.exports.new_player;