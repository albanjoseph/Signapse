# Neural Network Training

This directory contains the python tools used to train and evaluate our MobileNetv2 model on the ASL dataset.

### Python Env Setup

To configure the python environment, run `setup.sh` as shown:

```asm
bash setup.sh
```

This will generate and activate a virtual environment with the appropriate installed packages as listed in `requirememnts.txt`. FYI the following commands may be used to activate/deactivate this environment.

```asm
source venv/bin/activate #activates venv

deactivate #deactivates venv
```

### Dataset download

To train the model, the training data must first be downloaded. The training data we use are from Kaggle and accessible via the link: 

https://www.kaggle.com/datasets/grassknoted/asl-alphabet

Using the "Download" button on the site, add the `archive.zip` file to this directory. Use the following commands to rename and unzip the file.

```asm
mv archive.zip data.zip 
unzip data.zip 
```

This should produce a resultant directory, `data/` with the following structure:

```
├── asl_alphabet_test
│   └── asl_alphabet_test
└── asl_alphabet_train
    └── asl_alphabet_train
        ├── A
        ├── B
        ├── C
        ├── D
        ├── del
        ├── E
        ├── F
        ├── G
        ├── H
        ├── I
        ├── J
        ├── K
        ├── L
        ├── M
        ├── N
        ├── nothing
        ├── O
        ├── P
        ├── Q
        ├── R
        ├── S
        ├── space
        ├── T
        ├── U
        ├── V
        ├── W
        ├── X
        ├── Y
        └── Z
33 directories
```
### Training the Model

Use our training script to instancate the an instance of MobileNetv2 and train using Keras. Training can take some time, so maybe this is a good chance to make a cup of coffee. To run the training script use the following command from within the python environment:

```asm
python3 train.py 
```

Upon completion of the training script, the model will be saved in an intermediate tensorflow format. You can read more about Tensorflow `saved_model` format [here](https://www.tensorflow.org/guide/saved_model). 

### Conversion

For inference using OpenCV, the model must be converted into a format readable by OpenCV's `dnn` library. A list of formats is available [here](), we have opted to convert to protobuf format (ie `.pb` extension). The following script is used to convert the model:

```asm
python3 export.py
```

### Testing

The model can be tested within the OpenCV runtime and on a live camera feed by running our opencv test:
```asm
python3 test-opencv-feed.py
```
