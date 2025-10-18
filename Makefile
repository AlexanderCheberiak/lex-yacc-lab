# Makefile for C Parser with Lex/YACC
# Компілятор для синтаксичного аналізатора мови C

# Компілятор та флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g -O2
LEX = flex
YACC = bison
YFLAGS = -d -v

# Назви файлів
LEXER_SRC = lexer.l
PARSER_SRC = parser.y
AST_SRC = ast.c
MAIN_SRC = parser.tab.c lex.yy.c

# Цільові файли
TARGET = c_parser
PARSER_HEADER = parser.tab.h
LEXER_OUT = lex.yy.c
PARSER_OUT = parser.tab.c

# Всі об'єктні файли
OBJECTS = $(AST_SRC:.c=.o) $(MAIN_SRC:.c=.o)

# За замовчуванням
all: $(TARGET)

# Основна ціль - компіляція парсера
$(TARGET): $(OBJECTS)
	@echo "Компіляція основного виконуваного файлу..."
	$(CC) $(CFLAGS) -o $@ $^
	@echo "Парсер успішно скомпільовано!"

# Генерація парсера з YACC
$(PARSER_OUT) $(PARSER_HEADER): $(PARSER_SRC)
	@echo "Генерація парсера з YACC..."
	$(YACC) $(YFLAGS) $(PARSER_SRC)
	@echo "Парсер згенеровано!"

# Генерація лексера з Lex
$(LEXER_OUT): $(LEXER_SRC) $(PARSER_HEADER)
	@echo "Генерація лексера з Lex..."
	$(LEX) $(LEXER_SRC)
	@echo "Лексер згенеровано!"

# Компіляція об'єктних файлів
%.o: %.c
	@echo "Компіляція $<..."
	$(CC) $(CFLAGS) -c $< -o $@

# Спеціальна компіляція для lex.yy.c
lex.yy.o: lex.yy.c
	@echo "Компіляція $<..."
	$(CC) $(CFLAGS) -D_POSIX_C_SOURCE=200809L -c $< -o $@

# Запуск тестів
test: $(TARGET)
	@echo "Запуск тестів..."
	@echo "Тест 1: Простий приклад"
	./$(TARGET) tests/simple.c
	@echo ""
	@echo "Тест 2: Функції"
	./$(TARGET) tests/functions.c
	@echo ""
	@echo "Тест 3: Цикли"
	./$(TARGET) tests/loops.c
	@echo ""
	@echo "Тест 4: Умовні оператори"
	./$(TARGET) tests/conditionals.c

# Запуск інтерактивного режиму
interactive: $(TARGET)
	@echo "Запуск інтерактивного режиму..."
	@echo "Введіть C код (Ctrl+D для завершення):"
	./$(TARGET)

# Відкриття веб-візуалізатора
web: visualizer.html
	@echo "Відкриття веб-візуалізатора..."
	@if command -v xdg-open > /dev/null; then \
		xdg-open visualizer.html; \
	elif command -v open > /dev/null; then \
		open visualizer.html; \
	else \
		echo "Відкрийте visualizer.html у веб-браузері"; \
	fi

# Генерація документації
docs:
	@echo "Генерація документації..."
	@mkdir -p docs
	@echo "# C Parser Documentation" > docs/README.md
	@echo "" >> docs/README.md
	@echo "## Опис проекту" >> docs/README.md
	@echo "Синтаксичний аналізатор мови C з використанням Lex/YACC" >> docs/README.md
	@echo "" >> docs/README.md
	@echo "## Використання" >> docs/README.md
	@echo "\`\`\`bash" >> docs/README.md
	@echo "./c_parser input.c" >> docs/README.md
	@echo "\`\`\`" >> docs/README.md
	@echo "Документація згенерована в docs/README.md"

# Очищення проміжних файлів
clean:
	@echo "Очищення проміжних файлів..."
	rm -f $(LEXER_OUT) $(PARSER_OUT) $(PARSER_HEADER) parser.output
	rm -f *.o
	@echo "Проміжні файли видалено!"

# Повне очищення
distclean: clean
	@echo "Повне очищення..."
	rm -f $(TARGET)
	rm -f ast.json generated.c
	@echo "Всі файли видалено!"

# Встановлення залежностей (для Ubuntu/Debian)
install-deps:
	@echo "Встановлення залежностей..."
	@if command -v apt-get > /dev/null; then \
		sudo apt-get update && sudo apt-get install -y flex bison gcc make; \
	elif command -v yum > /dev/null; then \
		sudo yum install -y flex bison gcc make; \
	elif command -v brew > /dev/null; then \
		brew install flex bison; \
	else \
		echo "Будь ласка, встановіть flex, bison та gcc вручну"; \
	fi

# Перевірка залежностей
check-deps:
	@echo "Перевірка залежностей..."
	@command -v flex > /dev/null || (echo "flex не встановлено!" && exit 1)
	@command -v bison > /dev/null || (echo "bison не встановлено!" && exit 1)
	@command -v gcc > /dev/null || (echo "gcc не встановлено!" && exit 1)
	@command -v make > /dev/null || (echo "make не встановлено!" && exit 1)
	@echo "Всі залежності встановлено!"

# Створення архіву проекту
package: distclean
	@echo "Створення архіву проекту..."
	@cd .. && tar -czf lex-yacc-lab.tar.gz lex-yacc-lab/
	@echo "Архів створено: ../lex-yacc-lab.tar.gz"

# Допомога
help:
	@echo "Доступні команди:"
	@echo "  all          - Компіляція парсера (за замовчуванням)"
	@echo "  test         - Запуск тестів"
	@echo "  interactive  - Інтерактивний режим"
	@echo "  web          - Відкриття веб-візуалізатора"
	@echo "  docs         - Генерація документації"
	@echo "  clean        - Очищення проміжних файлів"
	@echo "  distclean    - Повне очищення"
	@echo "  install-deps - Встановлення залежностей"
	@echo "  check-deps   - Перевірка залежностей"
	@echo "  package      - Створення архіву проекту"
	@echo "  help         - Показати цю довідку"

# Фіктивні цілі
.PHONY: all test interactive web docs clean distclean install-deps check-deps package help

# Залежності
$(OBJECTS): $(PARSER_HEADER)
lex.yy.o: $(PARSER_HEADER)
parser.tab.o: $(PARSER_HEADER)
ast.o: ast.h
