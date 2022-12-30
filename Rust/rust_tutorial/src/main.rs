#![allow(unused)]
use std::{io::Chain, cmp::Ordering};
use std::io::{Write, BufReader, BufRead, ErrorKind};
use std::fs::File;
use rand::Rng;
use std::ops::Add;
use std::collections::HashMap;
use std::thread;
use std::rc::Rc;
use std::cell::RefCell;
use std::sync::{Arc, Mutex};
use std::time::Duration;
mod restaurant;
use crate::restaurant::order_food;
fn main() -> () {

    // User input

    /*
    let mut input: String = String::new();
    const GRETTINS: &str = "grettings";
    println!("Enter your name :");
    io::stdin().read_line(&mut input).expect("Didn't receibe input");
    println!("Hello , {} {}", input.trim(),GRETTINS);
    */


    /*
    Difference bettween Unsigned vs signed intengers
    */
    println!("u8 max: {}", u8::MAX);
    println!("i8 min: {}", i8::MIN);
    println!("u16 max: {}", u16::MAX);
    println!("i16 max: {}", i16::MAX);

    /// ramdom number
    let random_num: u8 = rand::thread_rng().gen_range(1..11);
    println!("ramdom: {}",random_num);
    println!("gen: {:?}",rand::thread_rng().gen::<(char)>().to_string());

    /// match
    let my_age: u8 = 18;
    let voting_age: u8 = 18;
    match my_age.cmp(&voting_age) {
        Ordering::Equal => println!("Gained the right"),
        Ordering::Less => println!("Can't Vote"),
        Ordering::Greater => println!("Can VOTE"),
    }
    
    
    /// arrays and loops
    let arr_1: [u8;4] = [1,2,3,4];
    println!("array: {:?}",arr_1);
    println!("len array: {}",arr_1.len());


    let mut loop_idx: usize = 0;
    loop {
        if loop_idx == arr_1.len(){
            break;
        }
        println!("array in index {}: {}",loop_idx,arr_1[loop_idx]);
        loop_idx += 1;
    }

    let arr_2 = ["first","second"];
    for val in arr_2.iter(){
        println!("Val: {}",val)
    }

    /// tuples
    let my_tuple: (i32,String,f32) = (48,"Derek".to_string(),50_000.00);

    let(v1,v2,v3) = my_tuple;

    /// String vs &str
    let mut st1: String = String::new();
    st1.push('A');
    st1.push_str(" word");
    st1.split_whitespace().for_each(|word| {
        println!("{}",word);
    });

    let st2: String =  st1.replace('A', "Another");
    println!("st2: {}",st2);

    let st3: String = String::from("a v c t r w");
    let mut v1: Vec<char> = st3.chars().collect();
    v1.sort();
    v1.dedup();
    for char_v1 in v1{
        println!("{}",char_v1)
    }
    let st4:&str = "Random String";
    let mut st5: String = st4.to_string();
    
    println!("st5: {}",st5);

    use std::str;

    let x: &[u8] = &[b'a', b'b', b'c'];
    print!("{}", str::from_utf8(x).unwrap());
    
    let st6 = String::from("One word");
    let st7 = String::from("other word");

    /// st6 dont exist anymore but st7 exist
    let st8 = st6+ " and "+ &st7;

    println!("st8: {}",st8);

    /// learaning "enum" and "impl"

    enum Day{
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    }

    impl Day {
        fn is_weekend(&self)->bool{
            match  self {
                Day::Saturday | Day::Sunday => true,
                _ => false
            }
        }
    }

    let today: Day  = Day::Monday;

    println!("Is today the weekend?\n {}",today.is_weekend());

    /// Vectors
    let vec1: Vec<i32> = Vec::new();
    let mut vec2: Vec<i32> = vec![1,2,3,4];
    vec2.push(5);
    let second =  &vec2[1];
    match vec2.get(1) {
        Some(second)=>println!("it is 2"),
        None => println!("it is not 2"),
    }
    for i in &mut vec2 {
        *i *=2;
    }
    for i in &vec2 {
        println!("{}",i);
    }
    println!("Pop : {:?}", vec2.pop());

    
    /// Functions
    fn get_sum(x: i8, y: i8) 
    -> i8
    {
        return x + y
    }
    fn get_multiplication_and_division(x: i32, y: i32) -> (i32,f32) {
        return (x * y, x as f32 / y as f32)
    }
    fn sum_list(list: &[i32]) ->i32{
        return list.iter().sum();
    }
    let list = [1,2,3,4];
    println!("{}", get_sum(19, 2));
    println!("{:?}",get_multiplication_and_division(3, 2));
    println!("sum {:?} = {}", list,sum_list(&list));

    /// Generics
    fn get_sum_gen<T:Add<Output = T>>(x: T,y: T) -> T{
        return x + y;
    }
    println!("{}",get_sum_gen(1, 1));
    println!("{}",get_sum_gen(1.4, 1.2));

    /// Ownership
    let str1 = String::from("World");
    let str2 = str1.clone();
    println!("Hello {}",str1);

    /// Hashmap
    let mut persons = HashMap::new();
    persons.insert("Pedro", 19);
    persons.insert("Buratti", 17);

    for (k,v) in persons.iter(){
        println!("{} is {} years old",k,v);
    }
    
    /// Structs
    struct Customer{
        name: String,
        age: u8,
        balance: f32,
    };

    let bob = Customer{
        name: String::from("bob"),
        age: 21,
        balance: 221.4,
    };
    trait Shape{
        fn new(lenght: f32, width: f32) -> Self;
        fn area(&self) -> f32;
    }
    
    struct Rectangle{
        lenght: f32,
        width: f32,
    }

    let rec = Rectangle{
        lenght: 3.1,
        width: 3.6
    };
    impl Shape for Rectangle {
        fn new(lenght: f32, width: f32) -> Self {
            return  Rectangle{lenght,width};
        }
        fn area(&self) -> f32 {
            return self.lenght * self.width
        }
    }

    println!("area of rec : {}",rec.area());

    // order_food();

    /// File io
    let path = "lines.txt";
    let output = File::create(path);
    let mut output = match output {
        Ok(file) => file,
        Err(e) => {
            panic!("Problem creating file: {:?}",e);
        }
    };
    write!(output, "Just some words").expect("Falied to write to file");
    
    let input = File::open(path).unwrap();
    let buffered = BufReader::new(input);

 
    for line in buffered.lines() {
        println!("{}", line.unwrap());
    }

    let output2 = File::create("rand.txt");
    let output2 = match output2 {
        Ok(file) => file,
        Err(error) => match error.kind() {
            ErrorKind::NotFound => match File::create("rand.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Can't create file: {:?}", e),
            },
            _other_error => panic!("Problem opening file : {:?}", error),
        },
    };
    /// Closures
    let can_vote = |age: i32| {
        age >= 18
    };
    println!("Can vote : {}", can_vote(8));

    let mut samp1 = 5;
    let print_var = || println!("samp1 = {}", samp1);
    print_var();
    samp1 = 10;

 
    let mut change_var = || samp1 += 1;
    change_var();
    println!("samp1 = {}", samp1);
    samp1 = 10;
    println!("samp1 = {}", samp1);
    fn use_func<T>(a: i32, b: i32, func: T) -> i32 where T: Fn(i32, i32) -> i32 {
        func(a, b)
    }

    let sum = |a, b| a + b;
    let prod = |a, b| a * b;

    println!("5 + 4 = {}", use_func(5, 4, sum));
    println!("5 * 4 = {}", use_func(5, 4, prod));

    /// Box
    let b_int1 = Box::new(10);

    println!("b_int1 = {}", b_int1);

    
    struct TreeNode<T> {
        pub left: Option<Box<TreeNode<T>>>,
        pub right: Option<Box<TreeNode<T>>>,
        pub key: T,
    }

    impl<T> TreeNode<T> {
        pub fn new(key: T) -> Self {
            TreeNode {
                left: None,
                right: None,
                key,
            }
        }

        pub fn left(mut self, node: TreeNode<T>) -> Self {
            self.left = Some(Box::new(node));
            self
        }

        pub fn right(mut self, node: TreeNode<T>) -> Self {
            self.right = Some(Box::new(node));
            self
        }
    }

    let node1 = TreeNode::new(1)
    .left(TreeNode::new(2))
    .right(TreeNode::new(3));
    
    /// Thread
    let thread1 = thread::spawn(|| {
        for i in 1..25 {
            println!("Spawned thread : {}", i);
          
            thread::sleep(Duration::from_millis(1));
        }
    });

    for i in 1..20 {
        println!("Main thread : {}", i);
        thread::sleep(Duration::from_millis(1));
    }
    thread1.join().unwrap();

    // ----- BANK ACCOUNT EXAMPLE -----

    pub struct Bank {
        balance: f32
    }

    fn withdraw(the_bank: &Arc<Mutex<Bank>>, amt:f32){
        let mut bank_ref = the_bank.lock().unwrap();

        if bank_ref.balance < 5.00{
            println!("Current Balance : {} Withdrawal a smaller amount",
            bank_ref.balance);
        } else {
            bank_ref.balance -= amt;
            println!("Customer withdrew {} Current Balance {}",
            amt, bank_ref.balance);
        }
    }

    fn customer(the_bank: Arc<Mutex<Bank>>) {
        withdraw(&the_bank, 5.00);
    }

    let bank: Arc<Mutex<Bank>> =
      Arc::new(Mutex::new(Bank { balance: 20.00 }));

    let handles = (0..10).map(|_| {

        let bank_ref = bank.clone();
        thread::spawn(|| {
            customer(bank_ref)
        })
    });

    for handle in handles {
        handle.join().unwrap();
    }

  
    
}


