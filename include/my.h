/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** struct
*/

#ifndef MY_H
    #define MY_H
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <stdbool.h>
void if_click(sfRenderWindow *window, sfEvent event,
    sfMusic* music);
void game(sfRenderWindow *window);
void display_background(sfRenderWindow *window,
    sfTexture *texture, sfSprite *sprite, sfVector2f scale);
sfMusic *initialize_music(const char *file);
void handle_event(sfRenderWindow *window,
    sfEvent event, sfMusic *music);
void draw_sprites(sfRenderWindow *window,
    sfSprite **sprites, int count);
sfRenderWindow *create_window(sfVideoMode mode);
void initialize_sprite(sfSprite **sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f position);
void draw_game_scene(sfRenderWindow *window, sfSprite *background,
    sfSprite *character, sfSprite *character2, sfSprite *my_cursor);
void handle_game_events(sfRenderWindow *window, sfEvent *event);
sfSprite *initialize_sprite_with_texture(const char *file,
    sfVector2f scale);
void movement(sfSprite *character, float *x, float *y, sfClock *clock);
int is_sprite_clicked(sfSprite *sprite, sfRenderWindow *window,
    sfEvent *event);
void animate_sprite(sfClock *clock, sfSprite *sprite,
    sfIntRect frames[], int frame_count, int *current_frame);
void movement_sol(sfSprite *character, float *x,
    float *y, sfClock *clock);
void essaye(sfRenderWindow *window, sfSprite **sprites,
    sfVector2f *positions, sfMusic *music, sfTexture **textures,
    sfVector2f *scales);
void initialize_sprites(sfSprite **background, sfSprite **goku,
    sfSprite **new_goku, sfSprite **my_cursor);
    sfText *initialize_text(sfFont **font);
    sfMusic *initialize_music_with_check();
void handle_sprite_clicks(sfSprite *goku, sfSprite *new_goku,
    sfRenderWindow *window, sfEvent *event, 
    float *x_position, float *y_position, float *x_position2,
    float *y_position2, int *score);
void update_sprite_animations(sfClock *animation_clock_goku,
    sfSprite *goku, sfIntRect frames[], int frame_count,
    int *current_frame_goku, sfClock *animation_clock_new_goku,
    sfSprite *new_goku, 
    sfIntRect frames2[], int frame_count2, int *current_frame_new_goku);
void update_sprite_positions(sfSprite *new_goku, float *x_position2,
    float *y_position2, sfClock *movement_clock, 
    sfSprite *goku, float *x_position, float *y_position);
void clean_up(sfMusic *music1, sfSprite *background,
    sfSprite *goku, sfSprite *new_goku, 
    sfClock *animation_clock_goku, sfClock *animation_clock_new_goku,
    sfClock *movement_clock);
void update_cursor(sfSprite *my_cursor, sfRenderWindow *window);
int main(void);
void game_loop(sfRenderWindow *window, sfSprite *background, sfSprite *goku,
    sfSprite *new_goku, sfSprite *my_cursor, sfText *text);
#endif

