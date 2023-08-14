
precision mediump float;
varying mediump vec2 texCoordVarying;
uniform sampler2D vTexture;
uniform vec4 uUVRange;
uniform vec2 uCornerRation;

void main() {

    vec3 centralColor;
    float sampleColor;
    vec2 blurCoordinates[20];

    float mul = 2.0;

    float mul_x = mul / 720.0;
    float mul_y = mul / 1280.0;


    blurCoordinates[0] = texCoordVarying + vec2(0.0 * mul_x,-10.0 * mul_y);
    blurCoordinates[1] = texCoordVarying + vec2(6.0 * mul_x,-6.0 * mul_y);
    blurCoordinates[2] = texCoordVarying + vec2(10.0 * mul_x,0.0 * mul_y);
    blurCoordinates[3] = texCoordVarying + vec2(6.0 * mul_x,6.0 * mul_y);
    blurCoordinates[4] = texCoordVarying + vec2(0.0 * mul_x,10.0 * mul_y);
    blurCoordinates[5] = texCoordVarying + vec2(-6.0 * mul_x,6.0 * mul_y);
    blurCoordinates[6] = texCoordVarying + vec2(-10.0 * mul_x,0.0 * mul_y);
    blurCoordinates[7] = texCoordVarying + vec2(-6.0 * mul_x,-6.0 * mul_y);


    sampleColor = texture2D(vTexture, texCoordVarying).g * 22.0;

    sampleColor += texture2D(vTexture, blurCoordinates[0]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[1]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[2]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[3]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[4]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[5]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[6]).g;
    sampleColor += texture2D(vTexture, blurCoordinates[7]).g;



    sampleColor = sampleColor/30.0;
    centralColor = texture2D(vTexture, texCoordVarying).rgb;

    float dis = centralColor.g - sampleColor + 0.5;


    if(dis <= 0.5)
    {
    dis = dis * dis * 2.0;
    }
    else
    {
    dis = 1.0 - ((1.0 - dis)*(1.0 - dis) * 2.0);
    }

    if(dis <= 0.5)
    {
    dis = dis * dis * 2.0;
    }
    else
    {
    dis = 1.0 - ((1.0 - dis)*(1.0 - dis) * 2.0);
    }

    if(dis <= 0.5)
    {
    dis = dis * dis * 2.0;
    }
    else
    {
    dis = 1.0 - ((1.0 - dis)*(1.0 - dis) * 2.0);
    }

    if(dis <= 0.5)
    {
    dis = dis * dis * 2.0;
    }
    else
    {
    dis = 1.0 - ((1.0 - dis)*(1.0 - dis) * 2.0);
    }

    if(dis <= 0.5)
    {
    dis = dis * dis * 2.0;
    }
    else
    {
    dis = 1.0 - ((1.0 - dis)*(1.0 - dis) * 2.0);
    }


    float aa= 1.03;
    vec3 smoothColor = centralColor*aa - vec3(dis)*(aa-1.0);

    float hue = dot(smoothColor, vec3(0.299,0.587,0.114));

    aa = 1.0 + pow(hue, 0.6)*0.1;
    smoothColor = centralColor*aa - vec3(dis)*(aa-1.0);

    smoothColor.r = clamp(pow(smoothColor.r, 0.6),0.0,1.0);
    smoothColor.g = clamp(pow(smoothColor.g, 0.6),0.0,1.0);
    smoothColor.b = clamp(pow(smoothColor.b, 0.6),0.0,1.0);


    vec3 lvse = vec3(1.0)-(vec3(1.0)-smoothColor)*(vec3(1.0)-centralColor);
    vec3 bianliang = max(smoothColor, centralColor);
    vec3 rouguang = 2.0*centralColor*smoothColor + centralColor*centralColor - 2.0*centralColor*centralColor*smoothColor;


    gl_FragColor = vec4(mix(centralColor, lvse, pow(hue, 0.6)), 1.0);
    gl_FragColor.rgb = mix(gl_FragColor.rgb, bianliang, pow(hue, 0.6));
    gl_FragColor.rgb = mix(gl_FragColor.rgb, rouguang, 0.25);



    mat3 saturateMatrix = mat3(
    1.1102,
    -0.0598,
    -0.061,
    -0.0774,
    1.0826,
    -0.1186,
    -0.0228,
    -0.0228,
    1.1772);

    vec3 satcolor = gl_FragColor.rgb * saturateMatrix;
    gl_FragColor.rgb = mix(gl_FragColor.rgb, satcolor, 0.18);
}
