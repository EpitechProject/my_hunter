/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** my_hunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "include/my.h"

sfRenderWindow *create_window(sfVideoMode mode)
{
    return sfRenderWindow_create(mode, "My Hunter", sfResize | sfClose, NULL);
}

void initialize_sprite(sfSprite **sprite, sfTexture *texture,
    sfVector2f scale, sfVector2f position)
{
    *sprite = sfSprite_create();
    sfSprite_setTexture(*sprite, texture, sfTrue);
    sfSprite_setScale(*sprite, scale);
    sfSprite_setPosition(*sprite, position);
}

void draw_sprites(sfRenderWindow *window, sfSprite **sprites, int count)
{
    for (int i = 0; i < count; i++) {
        sfRenderWindow_drawSprite(window, sprites[i], NULL);
    }
}

void handle_event(sfRenderWindow *window, sfEvent event, sfMusic *music)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        sfRenderWindow_close(window);
    }
    if (mouse.x >= 790 && mouse.x <= 1032 && mouse.y >= 590 && mouse.y <= 660) {
        if (event.type == sfEvtMouseButtonPressed) {
            sfRenderWindow_close(window);
        }
    }
    if_click(window, event, music);
}

void if_click(sfRenderWindow *window, sfEvent event, sfMusic* music)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (mouse.x >= 761 && mouse.x <= 1039 && mouse.y >= 328 &&
        mouse.y <= 400) {
        if (event.type == sfEvtMouseButtonPressed) {
            sfMusic_stop(music);
            game(window);
        }
    }
}
