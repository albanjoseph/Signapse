import cv2
import numpy as np
opencv_net = cv2.dnn.readNetFromTensorflow('frozen_graph.pb')
print(opencv_net)
cap = cv2.VideoCapture(0)
labels = ['W', 'del', 'G', 'X', 'Y', 'space', 'K', 'I', 'H', 'E', 'P', 'J', 'nothing', 'Q', 'S',
 'A', 'C', 'T', 'L', 'M', 'N', 'F', 'B', 'D', 'R', 'O', 'Z', 'V', 'U']
labels = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
          'W', 'X', 'Y', 'Z', 'del', 'space', 'nothing']

print(cv2.__version__)

while True:
    ret, frame = cap.read()
    frame=cv2.flip(frame,1)
    roi = frame[0:300, 0:300]
    #cv2.rectangle(frame, (0,0), (300, 300), (0,255), 2)
    resized=cv2.resize(roi, (224,224))
    input_blob = cv2.dnn.blobFromImage(resized, scalefactor=(1.0/255.0), swapRB=True)
    inp = np.random.standard_normal([1, 3, 224, 224]).astype(np.float32)
    opencv_net.setInput(input_blob)
    res = opencv_net.forward()
    class_id = np.argmax(res)
    conf_t = 0.6
    prediced_class_indexes = []
    for i, conf in enumerate(res[0]):
        if conf >= conf_t:
            prediced_class_indexes.append(i)
    if prediced_class_indexes:
        print('predictions are:')
    for prediction in prediced_class_indexes:
        print(labels[prediction])
    cv2.imshow('frame', frame)
    cv2.imshow('mask', resized)
    if(cv2.waitKey(1) & 0xFF==ord('q')):
        break
cap.release()
cv2.destroyAllWindows()
