// TODO: Given a vector of integers, leak its heap allocation.
//  Then split the resulting static slice into two halves and
//  sum each half in a separate thread.
//  Hint: check out `Vec::leak`.

use std::thread;

pub fn sum(slice: Vec<i32>) -> i32 {
    let slice = slice.leak();
    let (a, b) = slice.split_at(slice.len() / 2);
    let handler1: thread::JoinHandle<i32> = thread::spawn(move || -> i32 {
        a.into_iter().sum()
    });
    let handler2: thread::JoinHandle<i32> = thread::spawn(move || -> i32 {
        b.into_iter().sum()
    });
    handler2.join().unwrap() + handler1.join().unwrap()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn empty() {
        assert_eq!(sum(vec![]), 0);
    }

    #[test]
    fn one() {
        assert_eq!(sum(vec![1]), 1);
    }

    #[test]
    fn five() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5]), 15);
    }

    #[test]
    fn nine() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5, 6, 7, 8, 9]), 45);
    }

    #[test]
    fn ten() {
        assert_eq!(sum(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10]), 55);
    }
}
