from re import A
import pygame
import random
from arrays import *


turno = 0
pygame.init()
font = pygame.font.SysFont(None, 40)

textAlignLeft = 0
textAlignRight = 1
textAlignCenter = 2
textAlignBlock = 3

def drawText(surface, text, color, rect, font, align=textAlignLeft, aa=False, bkg=None):
    lineSpacing = -2
    spaceWidth, fontHeight = font.size(" ")[0], font.size("Tg")[1]

    listOfWords = text.split(" ")
    if bkg:
        imageList = [font.render(word, 1, color, bkg) for word in listOfWords]
        for image in imageList: image.set_colorkey(bkg)
    else:
        imageList = [font.render(word, aa, color) for word in listOfWords]

    maxLen = rect[2]
    lineLenList = [0]
    lineList = [[]]
    for image in imageList:
        width = image.get_width()
        lineLen = lineLenList[-1] + len(lineList[-1]) * spaceWidth + width
        if len(lineList[-1]) == 0 or lineLen <= maxLen:
            lineLenList[-1] += width
            lineList[-1].append(image)
        else:
            lineLenList.append(width)
            lineList.append([image])

    lineBottom = rect[1]
    lastLine = 0
    for lineLen, lineImages in zip(lineLenList, lineList):
        lineLeft = rect[0]
        if align == textAlignRight:
            lineLeft += + rect[2] - lineLen - spaceWidth * (len(lineImages)-1)
        elif align == textAlignCenter:
            lineLeft += (rect[2] - lineLen - spaceWidth * (len(lineImages)-1)) // 2
        elif align == textAlignBlock and len(lineImages) > 1:
            spaceWidth = (rect[2] - lineLen) // (len(lineImages)-1)
        if lineBottom + fontHeight > rect[1] + rect[3]:
            break
        lastLine += 1
        for i, image in enumerate(lineImages):
            x, y = lineLeft + i*spaceWidth, lineBottom
            surface.blit(image, (round(x), y))
            lineLeft += image.get_width()
        lineBottom += fontHeight + lineSpacing

    if lastLine < len(lineList):
        drawWords = sum([len(lineList[i]) for i in range(lastLine)])
        remainingText = ""
        for text in listOfWords[drawWords:]: remainingText += text + " "
        return remainingText
    return ""


pygame.display.set_caption('Gana y Juega')
orden_preguntas = random.sample(range(0,20), 20)

textRect = pygame.Rect(50, 50, 430, 270)

window = pygame.display.set_mode((480, 320), pygame.FULLSCREEN)
run = True

for turno in range(0,20):
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            break

    msg = preguntas[orden_preguntas[turno]]
    window.fill((255, 255, 255))
    textRect = pygame.Rect(25, 50, 430, 100)
    pygame.draw.rect(window, (255, 255, 255), textRect, 1)
    drawTextRect = textRect.inflate(-5, -5)
    drawText(window, msg, (0, 0, 0), drawTextRect, font, textAlignCenter, True)
    # opciones
    textRect = pygame.Rect(50,160,150,100) # left, top, width, height
    drawTextRect = textRect.inflate(-5, -5)
    drawText(window, opcionesa[orden_preguntas[turno]], (0, 0, 0), drawTextRect, font, textAlignCenter, True)
    textRect = pygame.Rect(300,160,150,100)
    drawTextRect = textRect.inflate(-5, -5)
    drawText(window, opcionesb[orden_preguntas[turno]], (0, 0, 0), drawTextRect, font, textAlignCenter, True)
    pygame.display.flip()
    # fin de opciones
    #Esperar respuesta por bluetooth
    while 1:
        for event in pygame.event.get():
            if event.type == pygame.KEYDOWN:
                print (event.key, 'pressed') # debug
                if event.key == 1073741882 or 282:
                    pygame.quit()
                    exit()


#Limpiar la pantalla
## Escribir contador de respuestas correcta
pygame.quit()
exit()