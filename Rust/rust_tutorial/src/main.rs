#![allow(unused)]

use std::io::Chain;

use rand::Rng;

fn main() {

    // User input

    // let mut input: String = String::new();
    // const GRETTINS: &str = "grettings";
    // println!("Enter your name :");
    // io::stdin().read_line(&mut input).expect("Didn't receibe input");
    // println!("Hello , {} {}", input.trim(),GRETTINS);


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



}