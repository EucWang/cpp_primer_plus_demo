//
// Created by 王新年 on 2019-04-14.
//

#include "emp.h"

using std::cout;
using std::cin;
using std::endl;

//--------------   class abstr_emp   ---------------------------

/**
 * default constructor
 */
abstr_emp::abstr_emp()
    : fname(""), lname(""), job(""){
}

/**
 * constructor method
 * @param fn  const string &
 * @param ln  const string &
 * @param j  const string &
 */
abstr_emp::abstr_emp(const string & fn, const string & ln, const string & j)
 : fname(fn), lname(ln), job(j){}


 /**
  * public method
  */
void abstr_emp::showAll() const {
    cout << fname << " " << lname << "'s job is " << job;
}

void abstr_emp::setAll() {
    cout << "Enter employee's first name : ";
    getline(cin, fname);
    cout << "Enter empolyee's last name : ";
    getline(cin, lname);
    cout << "Enter employee's job : ";
    getline(cin, job);
}

/**
 * friend method
 * @param os  ostream &
 * @param e  abstr_emp &
 * @return   ostream &
 */
std::ostream & operator<<(std::ostream & os, const abstr_emp & e) {
    os << e.fname << " " <<e.lname << "'s job is " << e.job;
    return os;
}


//--------------   class employee   ---------------------------

/**
 * default constructor
 */
employee::employee()
    : abstr_emp(){

}

employee::employee(const string &fn, const string &ln, const string &j)
    : abstr_emp(fn, ln, j){

}

void employee::showAll() const {
    abstr_emp::showAll();
}

void employee::setAll() {
    abstr_emp::setAll();
}


//--------------   class manager   ---------------------------

/**
 * default constructor
 */
manager::manager()
: abstr_emp(), inchargeof(0){
}

/**
 * constructor method
 * @param fn
 * @param ln
 * @param j
 * @param ico
 */
manager::manager(const string & fn, const string & ln, const string & j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico) {
}

/**
 * constructor method
 * @param e abstr_emp *
 * @param ico int
 */
manager::manager(const abstr_emp & e, int ico)
    : abstr_emp(e), inchargeof(ico){
}

/**
 * copy constructor
 * @param m class manager
 */
manager::manager(const manager & m)
        : abstr_emp(m){
    this->inchargeof = m.getInchargeof();
}

void manager::showData() const {
    cout << " inchargeof " << inchargeof << " employee.";
}

/**
 * public method
 */
void manager::showAll() const {
    abstr_emp::showAll();
    showData();
}

/**
 * public method
 */
void manager::setAll() {
    abstr_emp::setAll();
    cout << "Enter count of inchargeof : ";
    cin >> inchargeof;
    while(cin && cin.get() != '\n'){
        continue;
    }
}


//--------------   class fink   ---------------------------

/**
 * default constructor
 */
fink::fink() :abstr_emp() {
}

/**
 * constructor
 * @param fn
 * @param ln
 * @param j
 * @param rpo
 */
fink::fink(const string &fn,
        const string &ln,
        const string &j,
        const string &rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo){
}

fink::fink(const abstr_emp &e, const string &rpo)
    : abstr_emp(e), reportsto(rpo){
}

fink::fink(const fink &e)
    :abstr_emp((abstr_emp &)e), reportsto(e.getReportsto()){
}

void fink::showData() const{
    cout << " and (s)he is fink and reports to " << reportsto;
}

void fink::setData() {
    cout << "Enter fink's reportsto : ";
    getline(cin, reportsto);
}

void fink::showAll() const {
    abstr_emp::showAll();
    showData();
}

void fink::setAll() {
    abstr_emp::setAll();
    setData();
}


//--------------   class highfink   ---------------------------

/**
 * default constructor
 */
highfink::highfink()
    : abstr_emp(), manager(), fink() {
}

/**
 * highfink constructor
 * @param fn
 * @param ln
 * @param j
 * @param rpo
 * @param ico
 */
highfink::highfink(const string &fn,
        const string &ln,
        const string &j,
        const string &rpo,
        int ico)
    :abstr_emp(fn, ln, j),
    fink(fn,ln,j,rpo),
    manager(fn,ln,j,ico){
}

/**
 * constructor
 * @param e
 * @param rpo
 * @param ico
 */
highfink::highfink(const abstr_emp &e,
        const string &rpo,
        int ico)
    : abstr_emp(e),
    fink(e, rpo),
    manager(e, ico){
}

/**
 * constructor
 * @param f
 * @param ico
 */
highfink::highfink(const fink &f, int ico)
    : abstr_emp((abstr_emp &)f),
    fink(f),
    manager(f, ico){
}

highfink::highfink(const manager &m, const string &rpo)
    : abstr_emp((abstr_emp &)m), fink((abstr_emp &)m,rpo), manager(m){}

/**
 * copy constructor
 * @param h
 */
highfink::highfink(const highfink & h)
    : abstr_emp((abstr_emp &)h), fink((fink & )h), manager((manager &)h){
}

void highfink::showAll() const {
    abstr_emp::showAll();
    manager::showData();
    fink::showData();
}

void highfink::setAll() {
    manager::setAll();
    fink::setData();
}

