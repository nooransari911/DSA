import plotly
import plotly.graph_objects as go

# Create the data
language = ['C', 'C++',  'Rust', 'Go',  'Haskell', 'Julia', 'Java', 'HTML/CSS', 'JS', 'Nodejs', 'Python']
salary = [74, 75,  87, 91, 86, 75, 72, 70, 73, 57, 78]
experience = [11.5, 12,  9, 10, 9.5, 9, 10.5, 10, 10, 10, 10]
number = [61, 78,  52, 66, 6.2, 3.8, 127, 240, 300, 160, 200]

# Create the bubble chart
fig = go.Figure(data=[go.Scatter(x=experience, y=salary, mode='markers', marker_size=number, text=language, fillcolor="#ff00ff")])

# Show the plot
#fig.show()
plotly.offline.plot(fig, filename="/home/ansarimn/Downloads/DSA/Trees_and_Graphs/2023.html")
#fig.write_image("/home/ansarimn/Downloads/DSA/Trees_and_Graphs/2021_img.jpeg")
print ("completed")