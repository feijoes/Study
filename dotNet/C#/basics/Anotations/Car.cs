
namespace ClassTest{
    public class Car
    {
        private string? name;
        public Car(string nameCar)
        {
            Name = nameCar;
        }
        public virtual int CalculateSpeed(int y){
            return 100 * y; 
        }
        public string Name{
        
            get
            { 
                if (name != null) return name; 
                else return "null";
            }
            set
            {
                if (!(value =="")) name= value;
                else name = "null";
            }
        }
    }
}