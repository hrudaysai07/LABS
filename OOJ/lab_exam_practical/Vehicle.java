class InvalidRegistrationException extends Exception {
    public InvalidRegistrationException(String message) {
        super(message);
    }
}

class InvalidLoadException extends Exception {
    public InvalidLoadException(String message) {
        super(message);
    }
}

class Vehicle {
    public int reg_no;

    public Vehicle(int reg_no) throws InvalidRegistrationException {
        if (reg_no <= 0) {
            throw new InvalidRegistrationException("Registration number can't be zero or negative!");
        }
        this.reg_no = reg_no;
    }
}

class CommercialVehicle extends Vehicle {
    public int loadcapacity;

    public CommercialVehicle(int reg_no, int loadcapacity)
            throws InvalidRegistrationException, InvalidLoadException {

        super(reg_no);

        if (loadcapacity <= 0 || loadcapacity >100) {
            throw new InvalidLoadException("Load capacity can't be less than or equal to 0 and can't be greater than 100");
        }
        this.loadcapacity = loadcapacity;
        
    }  
}

public class Main {
    public static void main(String[] args) {

        try {
            CommercialVehicle v1 = new CommercialVehicle(0, 300);
            
        } catch (InvalidRegistrationException | InvalidLoadException e) {
            System.out.println(e.getMessage());
        }

        try {
            CommercialVehicle cv1 = new CommercialVehicle(5253, -5);
        } catch (InvalidLoadException e) {
            System.out.println(e.getMessage());
        } catch (InvalidRegistrationException e) {
            System.out.println(e.getMessage());
        }
    }
}
