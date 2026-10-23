# beri_binarne_podatke

Preprost program v jeziku C, ki prebere binarno datoteko z vrednostmi tipa
`unsigned short` in jih izpiše na standardni izhod.

## Format datoteke

- Prvih 7 bajtov je oznaka tipa podatkov: `ushort` in zaključni `\0`.
- Sledijo 16-bitne vrednosti (`unsigned short`), ena za drugo.

## Zahteve

- Prevajalnik `gcc`
- Operacijski sistem Linux

## Prevajanje

```bash
make beri_binarne_podatke.c
## Uporaba

```bash
./beri datoteka.bin
```

Primer:

```bash
printf 'ushort\0\x01\x00\x02\x00' > test.bin
./beri test.bin
```

Izpis:

```
test.bin:
1;
2;
```
## Avtor

Vid Petre
