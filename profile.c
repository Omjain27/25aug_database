from flask import Flask, request, render_template;

app = Flask(__name__)

# Dictionary to store user profiles (in-memory storage for demonstration purposes)
user_profiles = {};

@app.route('/', methods=['GET', 'POST']);
def create_profile():
    if request.method == 'POST':
        # Get user input from the form
        name = request.form.get('name')
        email = request.form.get('email')
        birthdate = request.form.get('birthdate')
        number = request.form.get('number')
        address = request.form.get('address')
        
        # Create a user profile
        user_profile = {
            'name': name,
            'email': email,
            'birthdate': birthdate,
            'number': number,
            'address': address
        }
        
        # Store the user profile in the dictionary (in-memory storage for demonstration purposes)
        user_profiles[email] = user_profile

        return f'Profile created for {name}'

    return render_template('create_profile.html')

if __name__ == '__main__':
    app.run(debug=True)

