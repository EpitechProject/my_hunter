/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** game_view2
*/

#include "../include/my.h"

void initialize_sprites(sfSprite **background, sfSprite **goku, sfSprite **new_goku, sfSprite **my_cursor)
{
    *background = initialize_sprite_with_texture("./img/background", (sfVector2f){2.7, 2.7});
    *goku = initialize_sprite_with_texture("./img/4.png", (sfVector2f){2.2, 2.2});
    *new_goku = initialize_sprite_with_texture("./img/3.png", (sfVector2f){2.2, 2.2});
    *my_cursor = initialize_sprite_with_texture("./img/sbz_ball.png", (sfVector2f){0.1, 0.1});
}

sfText *initialize_text(sfFont **font)
{
    *font = sfFont_createFromFile("img/Neucha-Regular.ttf");
    if (!*font)
        return NULL;

    sfText *text = sfText_create();
    sfVector2f text_pos = {100, 100};
    sfText_setPosition(text, text_pos);
    sfText_setColor(text, sfBlue);
    sfText_setFont(text, *font);
    sfText_setString(text, "Score : ");
    sfText_setCharacterSize(text, 100);
    return text;
}

sfMusic *initialize_music_with_check()
{
    sfMusic *music = initialize_music("./img/Dragon ball soundtrack 24.ogg");

    if (!music) {
        return NULL;
    }
    return music;
}

void handle_sprite_clicks(sfSprite *goku, sfSprite *new_goku, sfRenderWindow
    *window, sfEvent *event,
    float *x_position, float *y_position, float *x_position2,
    float *y_position2, int *score)
{
    if (is_sprite_clicked(goku, window, event)) {
        *x_position = -100.0f;
        *y_position = rand() % 600;
        (*score)++;
    }
    if (is_sprite_clicked(new_goku, window, event)) {
        *x_position2 = -600.0f;
        *y_position2 = 580;
        (*score)++;
    }
}

void update_cursor(sfSprite *my_cursor, sfRenderWindow *window)
{
    sfVector2i cursor_pos = sfMouse_getPositionRenderWindow(window);
    sfVector2f sbz_cursor_pos = {cursor_pos.x - 30, cursor_pos.y - 30};

    sfSprite_setPosition(my_cursor, sbz_cursor_pos);
}

void game_loop(sfRenderWindow *window, sfSprite *background, sfSprite *goku,
    sfSprite *new_goku, sfSprite *my_cursor, sfText *text)
    {
    sfIntRect frames[] = {{0, 0, 64, 64}, {64, 0, 64, 64},
        {128, 0, 64, 64}, {192, 0, 64, 64}};
    sfIntRect frames2[] = {
        {0, 0, 64, 88}, {64, 0, 64, 88}, {128, 0, 64, 88}, {192, 0, 64, 88}, 
        {256, 0, 64, 88}, {320, 0, 64, 88}, {384, 0, 64, 88}, {448, 0, 64, 88}
    };
    int frame_count = sizeof(frames) / sizeof(frames[0]);
    int frame_count2 = sizeof(frames2) / sizeof(frames2[0]);
    int current_frame_goku = 0, current_frame_new_goku = 0;
    float x_position = -100.0f, y_position = rand() % 600;
    float x_position2 = -600.0f, y_position2 = 580;
    int score = 0;
    sfClock *animation_clock_goku = sfClock_create();
    sfClock *animation_clock_new_goku = sfClock_create();
    sfClock *movement_clock = sfClock_create();
    sfEvent event;

    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        handle_game_events(window, &event);
        handle_sprite_clicks(goku, new_goku, window, &event, &x_position,
            &y_position, &x_position2, &y_position2, &score);
        update_sprite_animations(animation_clock_goku, goku, frames,
            frame_count, &current_frame_goku,
            animation_clock_new_goku, new_goku, frames2, frame_count2,
            &current_frame_new_goku);
        update_sprite_positions(new_goku, &x_position2, &y_position2,
            movement_clock, goku, &x_position, &y_position);
        update_cursor(my_cursor, window);
        draw_game_scene(window, background, goku, new_goku, my_cursor);
        sfRenderWindow_drawText(window, text, NULL);
    }
    sfClock_destroy(animation_clock_goku);
    sfClock_destroy(animation_clock_new_goku);
    sfClock_destroy(movement_clock);
}
