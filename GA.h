class Genom{
    public:
        Genom(int(&_genom_list)[100], int _evaluation):genom_list(_genom_list), evaluation(_evaluation){
        }
        auto& getGenom(){
            return this -> genom_list;
        }
        int getEvaluation(){
            return this -> evaluation;
        }
        void setGenom(int(&_genom_list)[100]){
            genom_list = _genom_list;
        }
    private:
     std::array<int, 100> genom_list;
     int evaluation;
}