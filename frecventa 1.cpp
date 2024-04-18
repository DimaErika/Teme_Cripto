from collections import Counter

# Calculăm frecvențele fiecărui caracter în textul criptat
frequency = Counter(encrypted_text)

# Sortăm frecvențele în ordine descrescătoare
sorted_frequencies = sorted(frequency.items(), key=lambda x: x[1], reverse=True)

# Vom afișa primele 5 cele mai frecvente caractere pentru a ajuta la identificarea deplasării
sorted_frequencies[:5]


//[('z', 193), ('L', 139), ('P', 83), ('T', 79), ('f', 64)]