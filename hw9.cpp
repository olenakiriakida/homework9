#include <iostream>
using namespace std;

/// <summary>
/// creats a student class
/// </summary>
class Student
{
private:
    string name;
    string surname;
    string father_name;
    string address;
    string birthday;
    string phone_number;
    int age;

    int* practice_rates = nullptr;
    int practice_rates_count = 0;

    int* exam_rates = nullptr;
    int exam_rates_count = 0;

    int* hometask_rates = nullptr;
    int hometask_rates_count = 0;

    /// <summary>
    /// creats a constructor with a delegation
    /// </summary>
public:
    Student() : Student("prismo", "the wishmaster", "almighty", "09.04.05", "cube", "077777777", 23) {
        cout << "Student has been created!" << endl;
    }

    Student(string name, string surname, string father_name, string birthday, string address, string phone_number, int age)
        : name(name), surname(surname), father_name(father_name), birthday(birthday), address(address), phone_number(phone_number), age(age) {}

    ~Student()
    {
        if (practice_rates != nullptr)
        {
            delete[] practice_rates;
            practice_rates = nullptr;
        }
        if (hometask_rates != nullptr)
        {
            delete[] hometask_rates;
            hometask_rates = nullptr;
        }
        if (exam_rates != nullptr)
        {
            delete[] exam_rates;
            exam_rates = nullptr;
        }
    }

    /// <summary>
    /// creats a name
    /// </summary>
    /// <param name="name"></param>
    void SetName(string name)
    {
        this->name = name;
    }

    /// <summary>
    /// returns a name
    /// </summary>
    /// <returns></returns>
    string GetName() const
    {
        return name;
    }

    void SetSurname(string surname)
    {
        this->surname = surname;
    }

    string GetSurname() const
    {
        return surname;
    }

    void SetFatherName(string father_name) {
        this->father_name = father_name;
    }

    string GetFatherName() const {
        return father_name;
    }
    /// <summary>
    /// sets birthday
    /// </summary>
    /// <param name="birthday"></param>
    void SetBirthday(string birthday)
    {
        this->birthday = birthday;
    }

    /// <summary>
    /// returns birthday
    /// </summary>
    /// <returns></returns>
    string GetBirthday() const
    {
        return birthday;
    }

    void SetAddress(string address) {
        this->address = address;
    }

    string GetAddress() const {
        return address;
    }

    void SetPhoneNumber(string phone_number) {
        this->phone_number = phone_number;
    }

    string GetPhoneNumber() const {
        return phone_number;
    }

    void SetAge(int age)
    {
        this->age = age;
    }

    int GetAge() const
    {
        return age;
    }

    void AddPracticeRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (practice_rates_count == 0)
        {
            practice_rates = new int[1];
            practice_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[practice_rates_count + 1];

            for (int i = 0; i < practice_rates_count; i++)
            {
                temp[i] = practice_rates[i];
            }
            temp[practice_rates_count] = rate;

            delete[] practice_rates;

            practice_rates = temp;
        }

        practice_rates_count++;
    }
    int GetPracticeGradesCount() const
    {
        return practice_rates_count;
    }
    int* GetPracticeGrades() const
    {
        return practice_rates;
    }

    void AddHometaskRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (hometask_rates_count == 0)
        {
            hometask_rates = new int[1];
            hometask_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[hometask_rates_count + 1];

            for (int i = 0; i < hometask_rates_count; i++)
            {
                temp[i] = hometask_rates[i];
            }
            temp[hometask_rates_count] = rate;

            delete[] hometask_rates;

            hometask_rates = temp;
        }

        hometask_rates_count++;
    }

    int GetHometasksGradesCount() const
    {
        return hometask_rates_count;
    }
    int* GetHometaskGrades() const
    {
        return hometask_rates;
    }

    void AddExamRate(unsigned int rate)
    {
        if (rate < 1 || rate > 12)
        {
            cout << "Incorrect value for parameter grade. Value must be from 1 to 12\n";
            throw "ERROR!";
        }

        if (exam_rates_count == 0)
        {
            exam_rates = new int[1];
            exam_rates[0] = rate;
        }
        else
        {
            cout << "Add yet another grade\n";

            int* temp = new int[exam_rates_count + 1];

            for (int i = 0; i < exam_rates_count; i++)
            {
                temp[i] = exam_rates[i];
            }
            temp[exam_rates_count] = rate;

            delete[] exam_rates;

            exam_rates = temp;
        }

        exam_rates_count++;
    }

    int GetExamGradesCount() const
    {
        return hometask_rates_count;
    }
    int* GetExamGrades() const
    {
        return exam_rates;
    }

    void ShowStudent() const {
        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Father Name: " << father_name << endl;
        cout << "Birthday: " << birthday << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << phone_number << endl;

        cout << "Practice rates: ";
        for (int i = 0; i < practice_rates_count; ++i) {
            cout << practice_rates[i] << " " << endl;
        }

        cout << "Hometask rates: ";
        for (int i = 0; i < hometask_rates_count; ++i) {
            cout << hometask_rates[i] << " " << endl;
        }

        cout << "Exam Grades: ";
        for (int i = 0; i < exam_rates_count; ++i) {
            cout << exam_rates[i] << " " << endl;
        }

    }

};

int main()
{
    Student s;
    s.SetName("prismo");
    s.SetSurname("the wishmaster");
    s.SetFatherName("almighty");
    s.SetBirthday("09.04.05");
    s.SetAddress("cube");
    s.SetPhoneNumber("003333333");
    s.AddPracticeRate(7);
    s.AddHometaskRate(5);
    s.AddExamRate(6);

    s.ShowStudent();
}