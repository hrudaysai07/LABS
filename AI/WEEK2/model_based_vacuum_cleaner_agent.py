def model_based_vacuum(status, location):
    model = {'A': 'Unknown', 'B': 'Unknown'}
    step = 1
    while True:
        model[location] = status[location]
        print(f"Step {step}: at {location}, model = {model}")
        if model['A'] == 'Clean' and model['B'] == 'Clean':
            print(" Action: No Operation")
            break
        elif model[location] == 'Dirty':
            print(" Action: Suck")
            status[location] = 'Clean'
            model[location] = 'Clean'
        elif location == 'A':
            print(" Action: Right")
            location = 'B'
        else:
            print(" Action: Left")
            location = 'A'
        step += 1

model_based_vacuum({'A': 'Dirty', 'B': 'Clean'}, location='B')
