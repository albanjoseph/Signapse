import tensorflow as tf
from tensorflow.python.framework.convert_to_constants import convert_variables_to_constants_v2
import os

from tensorflow.python.framework.convert_to_constants import convert_variables_to_constants_v2
model = tf.keras.models.load_model('models/my_model')
model.summary()

loaded = tf.saved_model.load('models/my_model')
infer = loaded.signatures['serving_default']

f = tf.function(infer).get_concrete_function(input_3=tf.TensorSpec(shape=[None, 224, 224, 3], dtype=tf.float32))
f2 = convert_variables_to_constants_v2(f)
graph_def = f2.graph.as_graph_def()

# Export frozen graph
with tf.io.gfile.GFile('frozen_graph.pb', 'wb') as f:
   f.write(graph_def.SerializeToString())
