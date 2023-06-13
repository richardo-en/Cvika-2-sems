export function create_random_number() {
    return Math.floor(Math.random() * (200 - 50) + 50)
}

export function get_jump() {
    return Math.floor(Math.random() * 11) - 5;
}

export function get_attack_range() {
    return Math.floor(Math.random() * 11);
}
