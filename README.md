# Basement of algorithms and programming (SEM02)

Source code and docs.

---

## Progress

 - [X] Labs
	- [X] 09
	- [X] 10
	- [X] 11
	- [X] 12
	- [X] 13
	- [X] 14
	- [X] 15
	- [X] 16
	- [X] 17
 - [X] Selfs
	- [X] 06
		- [X] diagram(-s)
		- [X] report
	- [X] 06
		- [X] diagram(-s)
		- [X] report
	- [X] 06
		- [X] diagram(-s)
		- [X] report
	- [X] 09
		- [X] diagram(-s)
		- [X] report
 - [X] converting to .docx with formatting script

---

## Docs

Can be explore by .md + .drawio (for normal people) or converted to .docx for dinosaurs (with normal people support).

### TOC

 - «Отчет самостоятельной работы №6» (Управляющие операторы)          // [~/docs/sels/06/report.md](docs/sels/06/report.md)
 - «Отчет самостоятельной работы №7» (Пользовательские функции)       // [~/docs/sels/07/report.md](docs/sels/07/report.md)
 - «Отчет самостоятельной работы №8» (Файловые потоки)                // [~/docs/sels/08/report.md](docs/sels/08/report.md)
 - «Отчет самостоятельной работы №9» (Обработка текстовой информации) // [~/docs/sels/09/report.md](docs/sels/09/report.md)

### Convert to .docx (Word)

Requirements:

 - Pandoc [jgm/pandoc](https://github.com/jgm/pandoc), tested on:
	```
	pandoc 3.9.0.2
	Features: +server +lua
	Scripting engine: Lua 5.4
	```

Recommended:

 - librsvg [GNOME/librsvg](https://github.com/GNOME/librsvg), - it handles with svg (diagram) correct - tested on:
	```
	rsvg-convert version 2.62.2
	```

How to:

 - Run `~/docs/scripts/export.sh` script from `scripts` dir;

`%`
```sh
cd ~/docs/scripts && chmod +x ./export.sh && ./export.sh
```

`>`
```
Generated: ~/docs/scripts/../output/0*.docx
...
```


---

Copyright (c) 2026 Maksim Bolotin (publicly known as Mark Bone) (github.com/kramenob)

All rights reserved.

This software and associated documentation files may not be copied, modified,
distributed, used, or incorporated into other works without explicit written
permission from the author.