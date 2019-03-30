# Your code here
def convert_temp(temperature, input_scale: 'kelvin', output_scale: 'celsius')
    if input_scale == 'celsius' and output_scale == 'fahrenheit'
        return temperature * 1.8 + 32.0
    elsif input_scale == 'celsius' and output_scale == 'kelvin'
        return temperature + 273.15
    elsif input_scale == 'fahrenheit' and output_scale == 'kelvin'
        return (temperature - 32.0)/1.8 + 273.15
    elsif input_scale == 'fahrenheit' and output_scale == 'celsius'
        return (temperature - 32.0)/1.8
    elsif input_scale == 'kelvin' and output_scale == 'celsius'
        return temperature - 273.15        
    elsif input_scale == 'kelvin' and output_scale == 'fahrenheit'
        return (temperature - 273.15) * 1.8 + 32.0
    else
        return temperature 
    end
end
