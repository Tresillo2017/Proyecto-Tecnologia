import pygame
import random

preguntas[
    "Q1. ¿Quién descubrió América?",  
    "Q2. ¿Cuándo terminó la Segunda Guerra Mundial?",  
    "Q3. ¿Cuántas especies de perros hay?",  
    "Q4. ¿Quién salvó al pueblo hebreo del faraón egipcio?",  
    "Q5. ¿Quién es el tenista con más Grand Slam?",
    "Q6. ¿Cómo se llama el actor de Harry Potter?",
    "Q7. ¿En qué continente se encuentran las Islas del Caribe?",
    "Q8. ¿Quién inventó la bombilla?",
    "Q9. ¿Cuál es el territorio con mayor población?",
    "Q10. ¿En qué ciudad española está el estadio conocido como Wanda Metropolitano?",
    "Q11. ¿Cuál es el río más caudaloso del mundo?",
    "Q12. ¿Quienes fueron los dos hermanos fundadores de Roma?",
    "Q13. ¿Quién era conocido como “el manco de Lepanto”?",
    "Q14. ¿Quién fue el famoso cantante del grupo musical Queen?",
    "Q15. ¿Quién es el YouTuber con más suscriptores?",
    "Q16. ¿Qué gran artista pintó la Capilla Sixtina?",
    "Q17. ¿Quién descubrió los satélites de Júpiter?",
    "Q18. ¿Qué país tiene más copas del mundo de fútbol?",
    "Q19. ¿De qué país es Lionel Andrés Messi?",
    "Q20. ¿Dónde jugó en la mayoría de su carrera Kobe Bryant?"
]

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



orden_preguntas = random.sample(range(1,21), 20)




textRect = pygame.Rect(50, 50, 430, 270)

window = pygame.display.set_mode((500, 500))
run = True
turno = 1
while run or turno!=20:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

    msg = preguntas[orden_preguntas[i]]
    window.fill((255, 255, 255))
    pygame.draw.rect(window, (255, 255, 255), textRect, 1)
    drawTextRect = textRect.inflate(-5, -5)
    drawText(window, msg, (0, 0, 0), drawTextRect, font, textAlignCenter, True)
    pygame.display.flip()

    #Esperar respuesta por bluetooth
    turno+1

#Limpiar la pantalla
## Escribir contador de respuestas correcta
pygame.quit()
exit()