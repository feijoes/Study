
import pygame
import random
import sys
from pygame.locals import *
from time import sleep

gray = (128, 128, 128)
height = 30
width = 30
vel = 30
name_blocks = ["I", "O", "S", "Z", "T"]
colors = [(0, 0, 128), (0, 128, 128), (128, 0, 128), (0, 128, 0), (128, 128, 0), (255, 0, 255), (0, 255, 255), (255, 255, 0), (0, 0, 255), (0, 255, 0), (255, 0, 0), (255, 255, 255)]
blocks = {"I": [(230, 10), (200, 10), (170, 10), (140, 10)], 'O': [(230, 10), (200, 10), (230, 40), (200, 40)], "S": [(230, 10), (200, 10), (200, 40), (170, 40)], "Z": [(170, 10), (200, 10), (200, 40), (230, 40)], "T": [(170, -20), (200, 10), (170, 10), (140, 10)]}


class Block:
    def __init__(self):

        self.random_block = random.choice(name_blocks)
        self.x = [x[0] for x in blocks[self.random_block]]
        self.y = [y[1] for y in blocks[self.random_block]]
        self.color = random.choice(colors)
        self.time = 0
        self.a = False
        self.bool = True
        self.bool1 = True

    def block(self):
        for i in range(len(self.x)):
            self.bloc = Rect(self.x[i], self.y[i], width, height)
            pygame.draw.rect(screen, self.color, self.bloc)

    def bool_change(self):
        if self.bool:
            self.bool = False
        else:
            self.bool = True

    def rotate(self):
        if self.random_block == "I":
            if self.bool:
                for i in range(len(self.x)):
                    self.x[i] = self.x[0]
                for i in range(1, len(self.x)):
                    self.y[i] = self.y[i-1] - 30

            elif not self.bool:
                for i in range(len(self.x)):
                    self.y[i] = self.y[0]
                for i in range(1, len(self.x)):
                    self.x[i] = self.x[i - 1] + 30

        if self.random_block == "S":
            if self.bool:
                self.x[2] = self.x[1] - 30
                self.x[3] = self.x[1]
                self.y[3] = self.y[1] + 30
            elif not self.bool:
                self.x[2] = self.x[1] + 30
                self.x[3] = self.x[1]
                self.y[3] = self.y[1] - 30

        if self.random_block == "Z":
            if self.bool:
                self.x[1] = self.x[2] + 30
                self.x[0] = self.x[2]
                self.y[0] = self.y[2] + 30
            if not self.bool:
                self.x[1] = self.x[2] - 30
                self.x[0] = self.x[2]
                self.y[0] = self.y[2] - 30
        if self.random_block == "T":
            print(f'bool {self.bool} bool1 { self.bool1}')
            if self.bool and self.bool1:
                print('a')
                self.x[1] = self.x[2]
                self.y[1] = self.y[2] + 30
            elif not self.bool and self.bool1:
                print('b')
                self.x[0] = self.x[2] + 30
                self.y[0] = self.y[2]
                self.bool1 = False
            elif self.bool and not self.bool1:
                print('c')
                self.x[3] = self.x[2]
                self.y[3] = self.y[2] - 30

            elif not self.bool and not self.bool1:
                self.x[1] = self.x[2] - 30
                self.y[1] = self.y[2]
                self.bool1 = True

        self.bool_change()

    def valid_rotantion(self):
        if self.random_block == "I":
            if not self.bool:
                if self.x[0] > 230:
                    return False
        if self.random_block == "S":
            if self.bool:
                print(self.x[1])
                if self.x[1] < 80:
                    return False
        return True

    def movement(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_LEFT] and all(i > 50 for i in self.x) and all(i < 410 for i in self.y):
            # decrement in x co-ordinate
            self.x[:] = [x - vel for x in self.x]
        if keys[pygame.K_RIGHT] and all(i < 500 - width for i in self.x) and all(i < 320 for i in self.x) and all(i < 410 for i in self.y):
            # increment in x co-ordinate
            self.x[:] = [x + vel for x in self.x]
        if keys[pygame.K_UP] and all(i < 410 for i in self.y) and self.valid_rotantion():
            # increment in x co-ordinate
            self.rotate()

    def fall(self):
        if self.time % 2 == 0 and all(i < 410 for i in self.y):
            self.y[:] = [y + vel for y in self.y]
            self.a = True
        self.time += 1

    def main(self):
        self.block()
        self.movement()
        self.fall()


class Tetris:
    def __init__(self):
        pygame.init()
        self.figure = None
        self.list_rect = []
        self.list_color = []

    def break_line(self):
        # 10-430
        listax = [x for x in range(50, 321, 30)]

        for z in range(10, 440, 30):
            lista = [x for x, y, _, _ in self.list_rect if y == z]
            if set(lista) == set(listax):
                self.list_rect.remove((x, z, 30, 30) for x in z)

    @staticmethod
    def grid():
        board = Rect(50, 10, 300, 450)
        pygame.draw.rect(screen, gray, board, 1)
        for y in range(10, 440, 30):
            for x in range(50, 330, 30):
                pygame.draw.rect(screen, gray, (x, y, 30, 30), 1)

    @staticmethod
    def lose():
        losescreen = pygame.display.set_mode((400, 500))
        lose = pygame.font.SysFont("monospace", 80)
        label = lose.render("You Lose", True, (255, 255, 0))
        losescreen.blit(label, (0, 100))
        pygame.display.update()
        sleep(1.5)
        pygame.quit()
        sys.exit()

    def new_figure(self):
        try:
            self.list_color.insert(0, self.figure.color)
            for i in range(len(self.figure.x)):
                self.list_rect.append(Rect(self.figure.x[i], self.figure.y[i], 30, 30))
            if 40 in self.figure.y:
                self.lose()

        except AttributeError:
            pass
        self.figure = Block()
        self.figure.a = False

    def criar(self):
        for i in range(len(self.list_rect)):
            pygame.draw.rect(screen, self.list_color[0], self.list_rect[i])

    def check_colision(self):

        for x, y, _, _ in self.list_rect:
            for i in range(len(self.figure.x)):
                if x == self.figure.x[i] and y - 30 <= self.figure.y[i]:

                    return True

        return False

    def main(self):
        self.check_colision()
        if self.check_colision():
            self.new_figure()
        self.figure.main()


te = Tetris()
te.new_figure()

while True:

    sleep(0)
    pygame.time.delay(100)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            sys.exit()
    screen = pygame.display.set_mode((400, 500))
    te.grid()
    te.criar()

    if 430 in te.figure.y and te.figure.a:
        te.new_figure()

    te.break_line()
    te.main()

    pygame.display.update()
