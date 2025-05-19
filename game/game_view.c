/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** game_view
*/

#include "../include/my.h"

sfSprite *initialize_sprite_with_texture(const char *file, sfVector2f scale)
{
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite *sprite = sfSprite_create();

    if (!texture) {
        return NULL;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}

void handle_game_events(sfRenderWindow *window, sfEvent *event)
{
    while (sfRenderWindow_pollEvent(window, event)) {
        if (event->type == sfEvtClosed ||
            (event->type == sfEvtKeyPressed &&
            event->key.code == sfKeyEscape)) {
            sfRenderWindow_close(window);
        }
    }
}

void draw_game_scene(sfRenderWindow *window, sfSprite *background,
    sfSprite *character, sfSprite *character2, sfSprite *my_cursor)
{
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_drawSprite(window, background, NULL);
    sfRenderWindow_drawSprite(window, character, NULL);
    sfRenderWindow_drawSprite(window, character2, NULL);
    sfRenderWindow_drawSprite(window, my_cursor, NULL);
    sfRenderWindow_display(window);
}

void update_sprite_animations(sfClock *animation_clock_goku, sfSprite *goku, sfIntRect frames[], int frame_count, 
                               int *current_frame_goku, sfClock *animation_clock_new_goku, sfSprite *new_goku, 
                               sfIntRect frames2[], int frame_count2, int *current_frame_new_goku)
{
    animate_sprite(animation_clock_goku, goku, frames, frame_count, current_frame_goku);
    animate_sprite(animation_clock_new_goku, new_goku, frames2, frame_count2, current_frame_new_goku);
}

void update_sprite_positions(sfSprite *new_goku, float *x_position2, float *y_position2, sfClock *movement_clock, 
                              sfSprite *goku, float *x_position, float *y_position)
{
    movement_sol(new_goku, x_position2, y_position2, movement_clock);
    movement(goku, x_position, y_position, movement_clock);
    sfClock_restart(movement_clock);
}
