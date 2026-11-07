// sotn-dsi - etapa 2: "hello world"
//
// Confere o basico do hardware antes de trazer o jogo:
//   - as duas telas funcionando (tela de cima = jogo, tela de baixo = toque)
//   - leitura dos botoes, ja com os nomes do mapeamento planejado
//   - leitura da tela de toque
//   - se o aparelho esta rodando em modo DSi (CPU a 133 MHz, 16 MB de RAM)

#include <nds.h>
#include <stdio.h>

static PrintConsole topScreen;
static PrintConsole bottomScreen;

// Mapeamento planejado para o port (ver docs/plano.md)
static const struct {
    u32 key;
    const char* name;
    const char* action;
} kButtons[] = {
    {KEY_B, "B", "Pular"},
    {KEY_Y, "Y", "Mao esquerda"},
    {KEY_A, "A", "Mao direita"},
    {KEY_X, "X", "Backdash"},
    {KEY_R, "R", "Subarma"},
    {KEY_L, "L", "Ultima transf."},
    {KEY_START, "START", "Menu"},
    {KEY_SELECT, "SELECT", "Livre"},
    {KEY_UP, "CIMA", "Direcional"},
    {KEY_DOWN, "BAIXO", "Direcional"},
    {KEY_LEFT, "ESQ.", "Direcional"},
    {KEY_RIGHT, "DIR.", "Direcional"},
};

static void drawTop(void) {
    consoleSelect(&topScreen);
    consoleClear();
    printf("\x1b[2;3HCastlevania: Symphony of the");
    printf("\x1b[3;12HNight - DSi");
    printf("\x1b[5;4H------------------------");
    printf("\x1b[7;2HEtapa 2: hello world");
    printf("\x1b[9;2HModo DSi: %s", isDSiMode() ? "SIM (133 MHz)" : "NAO (modo DS)");
    printf("\x1b[11;2HAperte os botoes e toque");
    printf("\x1b[12;2Hna tela de baixo.");
    printf("\x1b[22;2HSTART + SELECT: sair");
}

int main(void) {
    videoSetMode(MODE_0_2D);
    videoSetModeSub(MODE_0_2D);
    vramSetBankA(VRAM_A_MAIN_BG);
    vramSetBankC(VRAM_C_SUB_BG);

    consoleInit(&topScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, true, true);
    consoleInit(&bottomScreen, 3, BgType_Text4bpp, BgSize_T_256x256, 31, 0, false, true);

    if (isDSiMode()) {
        setCpuClock(true); // garante os 133 MHz do DSi
    }

    drawTop();

    const char* lastName = "-";
    const char* lastAction = "-";
    u32 frames = 0;

    while (1) {
        swiWaitForVBlank();
        scanKeys();
        u32 down = keysDown();
        u32 held = keysHeld();

        if ((held & KEY_START) && (held & KEY_SELECT)) {
            break;
        }

        for (unsigned i = 0; i < sizeof(kButtons) / sizeof(kButtons[0]); i++) {
            if (down & kButtons[i].key) {
                lastName = kButtons[i].name;
                lastAction = kButtons[i].action;
            }
        }

        consoleSelect(&bottomScreen);
        consoleClear();
        printf("\x1b[1;2HTELA DE BAIXO (toque)");
        printf("\x1b[3;2HUltimo botao: %s", lastName);
        printf("\x1b[4;2HAcao no port: %s", lastAction);

        if (held & KEY_TOUCH) {
            touchPosition touch;
            touchRead(&touch);
            printf("\x1b[6;2HToque: x=%3d  y=%3d", touch.px, touch.py);
            // a futura barra de transformacoes fica nos ultimos 48 px
            if (touch.py >= 144) {
                int slot = touch.px / 64;
                static const char* slots[] = {"Morcego", "Lobo", "Nevoa", "Menu"};
                printf("\x1b[7;2HBarra: %s", slots[slot > 3 ? 3 : slot]);
            } else {
                printf("\x1b[7;2HArea do mapa");
            }
        } else {
            printf("\x1b[6;2HToque: --");
        }

        printf("\x1b[22;2HQuadros: %lu", (unsigned long)frames++);
    }

    return 0;
}
