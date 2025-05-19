/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** game_view4
*/

#include "../include/my.h"

void game(sfRenderWindow *window)
{
    srand(time(NULL));
    sfSprite *background, *goku, *new_goku, *my_cursor;
    sfFont *font;
    sfText *text;
    sfMusic *music1;

    initialize_sprites(&background, &goku, &new_goku, &my_cursor);
    text = initialize_text(&font);
    if (!text || !background || !goku || !new_goku) return;
    music1 = initialize_music_with_check();
    if (!music1) {
        sfSprite_destroy(background);
        sfSprite_destroy(goku);
        sfSprite_destroy(new_goku);
        return;
    }
    game_loop(window, background, goku, new_goku, my_cursor, text);
    clean_up(music1, background, goku, new_goku, NULL, NULL, NULL);
}

void animate_sprite(sfClock *clock, sfSprite *sprite, sfIntRect frames[],
    int frame_count, int *current_frame)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    float delta_time = sfTime_asSeconds(elapsed);

    if (delta_time > 0.1f) {
        *current_frame = (*current_frame + 1) % frame_count;
        sfSprite_setTextureRect(sprite, frames[*current_frame]);
        sfClock_restart(clock);
    }
}
