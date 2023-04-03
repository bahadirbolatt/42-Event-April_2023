import requests

name = input("Enter the name of a Pokemon: ").lower()
response = requests.get("https://pokeapi.co/api/v2/pokemon/" + name)
if response.status_code != 200:
    print("Pokemon not found !")
    exit(1)

data = response.json()
print("Name: " + data["name"].capitalize())
print("Abilities:")
for ability in data["abilities"]:
    print("- " + ability["ability"]["name"].capitalize())