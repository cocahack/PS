fn main() {
  let mut input = String::new();
  std::io::stdin().read_line(&mut input);

  let mut answers = [0;26];

  for c in input.chars() {
    let mut c = c;
    if c.is_alphabetic() {
      let idx = (c as u8 - 'a' as u8) as usize;
      answers[idx] += 1;
    }
  }

  for i in answers.iter() {
    print!("{} ", i);
  }
}

