class VacuumCleanerAgent:
    def __init__(self, initial_location, room_states):

        self.location = initial_location
        self.room_states = room_states

    def reflex_agent(self):
        current_status = self.room_states[self.location]
        if current_status == "Dirty":
            return "Suck"
        elif self.location == "A":
            return "Right"
        elif self.location == "B":
            return "Left"

    def execute_simulation(self):
        print(f"State: {self.room_states}")
        print(f"Room: {self.location}\n")
        for step in range(1, 4):
            status = self.room_states[self.location]
            action = self.reflex_agent()
            print(f"Location: {self.location} | Status: {status} -> Action: {action}")
            if action == "Suck":
                self.room_states[self.location] = "Clean"
                print(f"-> Success: Cleaned Room {self.location}.")
            elif action == "Right":
                self.location = "B"
                print("-> Success: Moved Right to Room B.")
            elif action == "Left":
                self.location = "A"
                print("-> Success: Moved Left to Room A.")
            if self.room_states["A"] == "Clean" and self.room_states["B"] == "Clean":
                if step >= 2: 
                    print("\nFinal Environment State: Both rooms are Clean!")
                    break

starting_room = "A"
environment_status = {
    "A": "Dirty",
    "B": "Dirty"
}
vacuum = VacuumCleanerAgent(starting_room, environment_status)
vacuum.execute_simulation()
