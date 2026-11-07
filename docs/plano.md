# Plano do port

## Arquitetura

- **Código do jogo:** sotn-decomp (C), sem modificações sempre que possível.
- **psyz:** reimplementação da PSY-Q (SDK do PS1) usada pelo sotn-decomp para rodar fora do PS1.
  No PC ele usa backends SDL3. **O port = um backend novo do psyz para o DSi** (vídeo, áudio, entrada, arquivos).
- **Dados:** extraídos do disco do jogador com `sotn-disk` e convertidos para formatos do DS, lidos do cartão SD.

## Etapas

| # | Etapa | Estado |
|---|-------|--------|
| 1 | Ambiente de build (sotn-decomp + extração do disco + CI do devkitPro) | ✅ |
| 2 | Hello world no DSi + conversão de gráficos | 🚧 |
| 3 | Camada de hardware do DSi (backend psyz: vídeo, entrada, timer, "CD" no SD) | ⬜ |
| 4 | **Marco:** Alucard jogável numa área | ⬜ |
| 5 | Áudio: SFX no ARM7, música/vozes XA por streaming | ⬜ |
| 6 | Tela inferior: mapa, HUD, transformações por toque | ⬜ |
| 7 | Jogo completo: todas as áreas, castelo invertido, save no SD, otimização | ⬜ |
| 8 | Richter jogável (sem diálogos, como no Saturn) | ⬜ |
| 9 | Maria jogável (`mods/mariapsp-forpsx` / `USE_PLAYER_MARIA`) | ⬜ |
| 10 | Extras opcionais: conteúdo do Saturn, Castlevania (NES) como bônus | ⬜ |

## Controles

| DSi | Ação |
|-----|------|
| B | Pular (2× no ar = pulo duplo) |
| Y | Item da mão esquerda |
| A | Item da mão direita |
| X | Backdash |
| R | Subarma (Cima + ataque também funciona) |
| L | Repetir a última transformação |
| START | Menu |
| SELECT | Livre (ex.: zoom do mapa) |

## Tela inferior (256×192)

- **Mapa** (~144 px de altura): minimapa centralizado no jogador; arrastar = mover, toque duplo = zoom.
- **HUD** num canto: HP, MP, corações, subarma.
- **Barra** (48 px): morcego, lobo, névoa e menu (Alucard). Richter: item crashes. Maria: invocações.
