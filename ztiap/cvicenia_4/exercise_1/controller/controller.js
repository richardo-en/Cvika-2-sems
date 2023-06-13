import { move_player_around } from './../index.js';

var button_up = document.getElementById("button_up")
var button_left = document.getElementById("button_left")
var button_right = document.getElementById("button_right")
var button_down = document.getElementById("button_down")

button_up.onclick = function(){move_player_around(0,-25, 'up')}
button_left.onclick = function(){move_player_around(-25,0, 'left')}
button_right.onclick = function(){move_player_around(25,0, 'right')}
button_down.onclick = function(){move_player_around(0,25, 'down')}
