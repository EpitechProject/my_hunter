/*
** EPITECH PROJECT, 2024
** B-MUL-100-MAR-1-1-myhunter-tikinas.oughlis
** File description:
** my_hunter2
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "include/my.h"

sfMusic *initialize_music(const char *file)
{
    sfMusic *music = sfMusic_createFromFile(file);

    if (!music) {
        return NULL;
    }
    if (music) {
        sfMusic_setLoop(music, sfTrue);
        sfMusic_play(music);
    }
    return music;
}

void display_background(sfRenderWindow *window, sfTexture *texture,
    sfSprite *sprite, sfVector2f scale)
{
    initialize_sprite(&sprite, texture, scale, (sfVector2f){0, 0});
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = create_window(mode);
    sfMusic *music = initialize_music("./img/dbz4.ogg");
    sfSprite *sprites[5];
    sfVector2f scales[5] = {{2.6, 2.6}, {1.5, 1.5},
        {1.5, 1.5}, {1.5, 1.5}, {1.5, 1.5}};
    sfVector2f positions[6] = {{0, 0}, {680, 290}, {695, 410},
        {672, 558}, {530, -250}};
    sfTexture *textures[5] = { sfTexture_createFromFile("./img/gv.jpeg", NULL),
        sfTexture_createFromFile("./img/start.png", NULL),
        sfTexture_createFromFile("./img/menu.png", NULL),
        sfTexture_createFromFile("./img/exit.png", NULL),
        sfTexture_createFromFile("./img/ZHUNTER.png", NULL)
    };

    if (!window)
        return EXIT_FAILURE;
    essaye(window, sprites, positions, music, textures, scales);
    return 0;
}

void essaye(sfRenderWindow *window, sfSprite **sprites, sfVector2f *positions,
    sfMusic *music, sfTexture **textures,
    sfVector2f *scales)
{
    sfEvent event;

    for (int i = 0; i < 5; i++) {
        initialize_sprite(&sprites[i], textures[i], scales[i], positions[i]);
    }
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            handle_event(window, event, music);
        }
        sfRenderWindow_clear(window, sfWhite);
        draw_sprites(window, sprites, 5);
        sfRenderWindow_display(window);
    }
    sfMusic_destroy(music);
    for (int i = 0; i < 5; i++) {
        sfTexture_destroy(textures[i]);
        sfSprite_destroy(sprites[i]);
    }
    sfRenderWindow_destroy(window);
}
