

class IntCell {

    private:
      int value;

    public:
      IntCell(){
          this->value = int();
      }
      
      IntCell(int value){
          this->value = value;
      }

      ~IntCell(){

      }

      int getValue(){
          return this->value;
      }

      friend bool operator<(IntCell &const1, IntCell &const2){
          return const1.getValue() < const2.getValue();
      }

    friend bool operator>(IntCell &const1, IntCell &const2){
          return const1.getValue() > const2.getValue();
      }
};