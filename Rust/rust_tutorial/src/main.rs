#![allow(unused)]

use std::{io::Chain, cmp::Ordering};

use rand::Rng;

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

    println!("Is today the weekend {}",today.is_weekend());

    /// Vectors
    let vec1: Vec<i32> = Vec::new();
    let mut vec2: Vec<i32> = vec![1,2,3,4];
    vec2.push(5);
    let second =  &vec2[1];
    match vec2.get(1) {
        Some(second)=>println!("it is 2"),
        None => println!("it is not 2"),
    }
}

