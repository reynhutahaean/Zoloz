//
//  ZolozViewController.swift
//  Zoloz
//
//  Created by Reynaldo Cristinus Hutahaean on 14/08/23.
//

import UIKit

class ZolozViewController: UIViewController {
    
    var presenter: ZolozViewToPresenter?
    
    init() {
        super.init(nibName: String(describing: ZolozViewController.self), bundle: Bundle(for: ZolozViewController.self))
    }
    
    required init?(coder aDecoder: NSCoder) {
        super.init(coder: aDecoder)
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }
    
    @IBAction func didTappedButton(_ sender: Any) {
        presenter?.didTappedButton()
    }
}

extension ZolozViewController: ZolozPresenterToView {
    
}
