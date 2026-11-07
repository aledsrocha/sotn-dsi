# sotn-dsi

Port nativo de **Castlevania: Symphony of the Night** para **Nintendo DSi**, baseado no [sotn-decomp](https://github.com/Xeeynamo/sotn-decomp).

*Native Nintendo DSi port of Castlevania: Symphony of the Night, built on sotn-decomp. No game data included: you build it from your own PS1 disc.*

> **Este repositório não contém nenhum dado do jogo.** Gráficos, sons e código original são da Konami.
> Os dados são extraídos do disco de PS1 (NTSC-U, SLUS-00067) do próprio jogador.

## Estado

🚧 Em desenvolvimento: **etapa 2 (hello world)**. Ainda não é jogável. Veja o [plano](docs/plano.md).

## Como baixar a build

Cada push gera um `.nds` automaticamente:
**Actions → Build → (última execução) → Artifacts → `sotn-dsi`**.

Teste no [melonDS](https://melonds.kuribo64.net/) (modo DSi) ou num DSi com Unlaunch / TWiLight Menu++.

## Como compilar localmente

Requer [devkitPro](https://devkitpro.org/wiki/Getting_Started) com devkitARM e libnds.

```sh
make
```

## Licença

AGPL-3.0, a mesma do sotn-decomp.
