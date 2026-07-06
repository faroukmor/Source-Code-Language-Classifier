# Source Code Language Classifier
A from-scratch NLP project built with PyTorch to classify C and Java source code files. This project serves as a deep dive into text preprocessing, vocabulary building, and the limitations of traditional feature extraction in the context of programming languages.

# How It Works
The pipeline is built entirely using core Python and PyTorch, without relying on high-level NLP libraries:

Data Ingestion: Reads .c and .java files from a local directory.
Tokenization: Uses custom Regular Expressions to split source code into meaningful tokens, explicitly isolating operators and brackets (e.g., splitting main() into main, (, )).
Vocabulary Building: Constructs a dynamic dictionary mapping unique tokens to integer IDs.
Feature Extraction (Bag of Words): Converts variable-length source code into fixed-size numerical vectors based on token frequency.
Classification: Feeds the vectors into a custom Feed-Forward Neural Network (nn.Module) to predict the programming language.
# Challenges & Learnings
Building this project was a journey of debugging and realization:

The "Blind" Model: Initially, the model cheated by memorizing the training data (Loss dropped to 0.0000), which led to the implementation of out-of-sample testing to check for real generalization.
Tokenization Matters: The model initially failed to classify Java correctly. I discovered that standard string splitting (e.g., treating main() as one word) hid crucial structural differences. Switching to a regex-based tokenizer that isolates brackets and operators dramatically improved accuracy.
Bag of Words Limitations: I learned firsthand why Bag of Words struggles with code. Because C and Java share a massive amount of syntax ({, }, ;, int), simple word frequency isn't enough, highlighting the exact reason why modern AI uses Embeddings and Transformers for code analysis.
# Tech Stack
Language: Python 3
Deep Learning: PyTorch (torch, torch.nn, DataLoader)
Text Processing: Native re (Regex)
Environment: Windows 11, CPU-only training
# How to Run
Clone the repository:
git clone https://github.com/YOUR_USERNAME/Source-Code-Language-Classifier.git
Install dependencies:
```bash
pip install torch
```
Run the training and testing script

(Note: The dataset/ folder contains sample files to test the pipeline immediately. To train on your own codebase, simply change the folder_path variable).
# Author
Built by Farouk as a foundational step in understanding NLP and PyTorch mechanics beyond tutorials.
