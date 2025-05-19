/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** game_view3
*/

#include "../include/my.h"

void movement(sfSprite *character, float *x, float *y, sfClock *clock)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    float delta_time = sfTime_asSeconds(elapsed);
    float speed = 600.0f;

    *x += speed * delta_time;
    if (*x > 1920) {
        *x = -sfSprite_getGlobalBounds(character).width;
        *y = rand() % 600;
    }
    sfSprite_setPosition(character, (sfVector2f){*x, *y});
}

void movement_sol(sfSprite *character, float *x, float *y, sfClock *clock)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    float delta_time = sfTime_asSeconds(elapsed);
    float speed = 320.0f;

    *x += speed * delta_time;
    if (*x > 1920) {
        *x = -sfSprite_getGlobalBounds(character).width;
        *y = 580;
    }
    sfSprite_setPosition(character, (sfVector2f){*x, *y});
}

int is_sprite_clicked(sfSprite *sprite, sfRenderWindow *window, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed) {
        sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(window);
        sfFloatRect sprite_bounds = sfSprite_getGlobalBounds(sprite);
        if (sfFloatRect_contains(&sprite_bounds, mouse_pos.x, mouse_pos.y)) {
            return 1;
        }
    }
    return 0;
}

sfText *initialize_score_text(sfFont *font)
{
    sfText *score_text = sfText_create();
    sfText_setFont(score_text, font);
    sfText_setCharacterSize(score_text, 30);
    sfText_setColor(score_text, sfBlack);
    return score_text;
}

void clean_up(sfMusic *music1, sfSprite *background, sfSprite *goku, sfSprite *new_goku, 
              sfClock *animation_clock_goku, sfClock *animation_clock_new_goku, sfClock *movement_clock)
{
    sfMusic_destroy(music1);
    sfSprite_destroy(background);
    sfSprite_destroy(goku);
    sfSprite_destroy(new_goku);
    sfClock_destroy(animation_clock_goku);
    sfClock_destroy(animation_clock_new_goku);
    sfClock_destroy(movement_clock);
}
