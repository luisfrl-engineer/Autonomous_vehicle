# PLANO.md — Carro Autónomo 2WD (Embedded C/C++)

Projeto: `carro-autonomo` (ESP32 + ESP-IDF + FreeRTOS). Mentoria de carreira embedded C/C++, objetivo: emprego júnior no Porto/Aveiro.

Nota de arquitetura: o projeto usa **ESP-IDF** (não Arduino framework) desde a Semana 0, por decisão consciente — mais próximo do que se usa em produtos reais, escreve-se os próprios drivers em vez de depender de bibliotecas Arduino de terceiros, e já se vive dentro de CMake desde o início.

## Cronograma — 20 semanas

### Semana 0 — Setup ✅ CONCLUÍDO
Git, GitHub, VS Code, PlatformIO, driver USB, projeto ESP-IDF, Blink no LED interno.

### Fase 1 — C++ Fundamentos (Semanas 1-8, ritmo reduzido até à defesa em setembro)
Objetivo: ler e escrever C++ com confiança para começar o código do carro sem lutar com sintaxe. Tudo com lente embedded.

| Sem. | Conteúdo | Prática |
|---|---|---|
| 1 | Sintaxe C++ vs C, iostream, namespaces | Reescrever 3 programas simples de C para C++ |
| 2 | Classes: atributos, métodos, construtores/destrutores | Modelar uma classe `Sensor` simples |
| 3 | Encapsulamento, getters/setters com validação | Expandir a classe `Sensor` |
| 4 | Referências vs ponteiros | Exercícios de passagem por referência vs ponteiro |
| 5 | STL: `vector` — e `std::array` como alternativa embedded | Guardar leituras de um sensor simulado; comparar os dois |
| 6 | STL: `string`, `map`; `const`/`constexpr` | Mini-logger de eventos com timestamp |
| 7 | RAII e gestão de recursos | Classe que gere um recurso com RAII |
| 8 | Templates básicos + revisão; exceções off em embedded (consciência) | Mini-projeto: classe genérica `Buffer<T>` estática |

Se a defesa/exames comerem uma ou duas semanas, a Fase 1 estica — está previsto, não é falha.

### Fase 2 — Embedded + RTOS + Carro + Testes (Semanas 9-16)

| Sem. | Conteúdo teórico | No carro (prática) |
|---|---|---|
| 9 | GPIO, arquitetura ESP32, PlatformIO/ESP-IDF a fundo | Piscar LED; ler HC-SR04 isoladamente |
| 10 | FreeRTOS: tasks, `vTaskDelay` | Task Sensor a correr sozinha |
| 11 | Filas (queues) entre tasks | Task Sensor envia leituras para uma fila |
| 12 | Mutexes e secções críticas | Task Motor protegida por mutex |
| 13 | ISRs, timers, prioridades | Task Decisão a consumir a fila e decidir ação |
| 13-14 | **Testes unitários: Unity, `pio test`** | Testar a lógica de decisão isolada do hardware |
| 14 | I2C/SPI na prática | Integrar o IMU via I2C |
| 15 | UART/Serial debugging, watchdog | Debug do sistema completo, 3 tasks em paralelo |
| 16 | Timing determinístico, revisão | Carro funcional: deteta obstáculo e reage — gravar vídeo |

### Fase 3 — CAN Bus + CMake + Consolidação (Semanas 17-20)

| Sem. | Conteúdo | Prática |
|---|---|---|
| 17 | Conceitos CAN: frames, arbitragem, IDs | Ligar 1.º MCP2515 ao ESP32, testar SPI |
| 18 | Bibliotecas CAN para ESP32 (ex.: autowp-mcp2515) | Loopback: enviar mensagem de um ESP32 para si mesmo |
| 19 | Comunicação entre 2 nós | 2.º ESP32 + MCP2515 a receber e responder |
| 19-20 | CMake — CMakeLists.txt, targets, build | Ler/editar o CMake do próprio projeto ESP-IDF |
| 20 | Documentação e consolidação | README do repo; revisão de todo o código; post no LinkedIn |

### Fase 4 — Candidaturas + melhoria contínua (a partir de nov/dez)
Começar candidaturas com o carro a andar, mesmo incompleto. Empresas-alvo: Capgemini (V.N. Gaia), Strypes, Spin.Works, Critical FlyTech, Tekever.

## Checklist — Semana 1: Sintaxe C++ vs C

- [ ] Perceber diferenças-chave: `namespace`, `iostream` vs `printf`, `bool` nativo, declarações de variáveis em qualquer ponto do bloco
- [ ] Entender porquê `printf`/`Serial.print` continuam a dominar em firmware real (overhead do `iostream`, tamanho de binário, sem alocação dinâmica escondida)
- [ ] Reescrever **Programa 1** de C para C++ (ver proposta abaixo)
- [ ] Reescrever Programa 2 (a propor depois de fechar o 1.º)
- [ ] Reescrever Programa 3 (a propor depois de fechar o 2.º)
- [ ] Commit no GitHub com os 3 programas, mensagem clara (ex.: `feat: reescreve exercicios C para C++ (semana 1)`)

## Estado do hardware
Tudo em mãos: ESP32 DevKit, chassis 2WD, TB6612FNG, LM2596, 2× motores TT, HC-SR04, IMU MPU-6500, baterias 18650 2S1P. Só os 2× MCP2515 ficam para comprar perto da Fase 3 (~semana 17).